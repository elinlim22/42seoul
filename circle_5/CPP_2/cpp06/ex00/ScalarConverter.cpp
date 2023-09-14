#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ScalarConverter::ScalarConverter() : flag(0), returnChar(0), returnInt(0), returnFloat(0), returnDouble(0) {

}

ScalarConverter::ScalarConverter(const ScalarConverter& a) {
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ScalarConverter::~ScalarConverter() {}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& a) {
	if (this != &a) {
		this->flag = a.flag;
		this->returnChar = a.returnChar;
		this->returnInt = a.returnInt;
		this->returnFloat = a.returnFloat;
		this->returnDouble = a.returnDouble;
	}
	return *this;
}
/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void ScalarConverter::checkType(const std::string& source) {
	// Case literals - Char
	if (source.length() == 1 && !isdigit(source[0])) this->flag = CFLAG;

	// Case nan, inf, inff
	else if (source == "nanf" || source == "+inff" || source == "-inff") this->flag = FFLAG;
	else if (source == "nan" || source == "+inf" || source == "-inf") this->flag = DFLAG;

	// Case ltierals - Float, Double
	else if (source.find('.') != std::string::npos && isFloatOrDouble(source)) {
		if (source[source.length() - 1] == 'f') this->flag = FFLAG;
		else this->flag = DFLAG;
	}

	// Case literals - Int
	else if (isInt(source))this->flag = IFLAG;
}

void ScalarConverter::doCast(const std::string& source) {
	try {
		switch (getFlag()) {
			case CFLAG:
				convertToChar(source);
				break ;
			case IFLAG:
				convertToInt(source);
				break ;
			case FFLAG:
				convertToFloat(source);
				break ;
			case DFLAG:
				convertToDouble(source);
				break ;
			default:
				throw std::runtime_error("Nothing flagged");
		}
	} catch (ScalarConverter::printException& e) {
		e.exPrint();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

int ScalarConverter::getFlag() const {
	return this->flag;
}


void ScalarConverter::convertToChar(const std::string& source) {
	this->returnChar = source[0];
	this->returnInt = static_cast<int>(returnChar);
	this->returnFloat = static_cast<float>(returnChar);
	this->returnDouble = static_cast<double>(returnChar);
}

void ScalarConverter::convertToInt(const std::string& source) {
	this->returnInt = std::atoi(source.c_str());
	this->returnChar = static_cast<char>(returnInt);
	this->returnFloat = static_cast<float>(returnInt);
	this->returnDouble = static_cast<double>(returnInt);
}

void ScalarConverter::convertToFloat(const std::string& source) {
	// Exception
	if (source == "nanf") throw printException(NANP);
	else if (source.find("inff") != std::string::npos) {
		if (source[0] == '+') throw printException(P_INFP);
		else if (source[0] == '-') throw printException(N_INFP);
	}

	// removing 'f'
	std::string strWithoutF = source;
	size_t fPosition = strWithoutF.find('f');
	if (fPosition != std::string::npos)	strWithoutF.erase(fPosition, 1);

	float ret;
	std::istringstream iss(strWithoutF);
	iss >> ret;
	this->returnFloat = ret;
	this->returnInt = static_cast<int>(returnFloat);
	this->returnDouble = static_cast<double>(returnFloat);
	this->returnChar = static_cast<char>(returnFloat);
}

void ScalarConverter::convertToDouble(const std::string& source) {
	// Exception
	if (source == "nan") throw printException(NANP);
	else if (source.find("inf") != std::string::npos) {
		if (source[0] == '+') throw printException(P_INFP);
		else if (source[0] == '-') throw printException(N_INFP);
		else throw std::runtime_error("Wrong input");
	}

	double ret;
	std::istringstream iss(source);
	iss >> ret;
	this->returnDouble = ret;
	this->returnInt = static_cast<int>(returnDouble);
	this->returnFloat = static_cast<float>(returnDouble);
	this->returnChar = static_cast<char>(returnDouble);
}

void ScalarConverter::printValue() const {
	if (std::isprint(this->returnChar)) std::cout << "Char: " << this->returnChar << std::endl;
	else std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << this->returnInt << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "Float: ";
	if (returnDouble >= 8388607 && returnDouble <= FLT_MAX)
		std::cout << this->returnDouble << "f" << std::endl;
	else
		std::cout << this->returnFloat << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "Double: " << this->returnDouble << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Exception class                              */
/* -------------------------------------------------------------------------- */
ScalarConverter::printException::printException(int _exType) {
	this->exType = _exType;
}

void ScalarConverter::printException::exPrint() throw() {
	switch (this->exType) {
		case NANP:
			std::cout << "Char: impossible" << std::endl;
			std::cout << "Int: impossible" << std::endl;
			std::cout << "Float: nanf" << std::endl;
			std::cout << "Double: nan" << std::endl;
			std::exit(EXIT_SUCCESS);
		case P_INFP:
			std::cout << "Char: impossible" << std::endl;
			std::cout << "Int: impossible" << std::endl;
			std::cout << "Float: +inff" << std::endl;
			std::cout << "Double: +inf" << std::endl;
			std::exit(EXIT_SUCCESS);
		case N_INFP:
			std::cout << "Char: impossible" << std::endl;
			std::cout << "Int: impossible" << std::endl;
			std::cout << "Float: -inff" << std::endl;
			std::cout << "Double: -inf" << std::endl;
			std::exit(EXIT_SUCCESS);
		default:
			std::cerr << "Error: Exception type not specified" << std::endl;
			std::exit(EXIT_FAILURE);
	}
}

/* -------------------------------------------------------------------------- */
/*                               Other function                               */
/* -------------------------------------------------------------------------- */
bool isInt(const std::string& source) {
	size_t i = 0;
	if (source[0] == '-' || source[0] == '+') ++i;
	for (; i < source.length(); ++i) {
		if (!isdigit(source[i])) return false;
	}
	return true;
}

bool isFloatOrDouble(const std::string& input) {

	// removing 'f'
	std::string strWithoutF = input;
	size_t fPosition = strWithoutF.find('f');
	if (fPosition != std::string::npos && strWithoutF[strWithoutF.length() - 1] == 'f')	strWithoutF.erase(fPosition, 1);

	std::istringstream iss(strWithoutF);
	float f;
	double d;

	// try float
	iss >> f;
	if (!iss.fail() && iss.eof()) {
		return true;
	}

	// else try double
	iss.clear();
	iss.str(input);
	iss >> d;
	if (!iss.fail() && iss.eof()) {
		return true;
	}

	return false;
}
