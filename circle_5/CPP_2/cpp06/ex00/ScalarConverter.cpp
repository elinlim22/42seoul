#include "ScalarConverter.hpp"

int ScalarConverter::flag = 0;
char ScalarConverter::returnChar = 0;
int ScalarConverter::returnInt = 0;
float ScalarConverter::returnFloat = 0.0f;
double ScalarConverter::returnDouble = 0.0;

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& a) {
	static_cast<void>(a);
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ScalarConverter::~ScalarConverter() {}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ScalarConverter& ScalarConverter::operator= (const ScalarConverter& a) {
	static_cast<void>(a);
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */

/* --------------------------------- private -------------------------------- */
void ScalarConverter::convertToChar(const std::string& source) {
	returnChar = source[0];
}

void ScalarConverter::convertToInt(const std::string& source) {
	int i;
	std::istringstream iss(source);
	iss >> i;
	if (!iss.fail() && iss.eof()) returnInt = i;
	else throw std::runtime_error("conversion failed");
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

	float f;
	std::istringstream iss(strWithoutF);
	iss >> f;
	if (!iss.fail() && iss.eof()) returnFloat = f;
	else throw std::runtime_error("conversion failed");
}

void ScalarConverter::convertToDouble(const std::string& source) {
	// Exception
	if (source == "nan") throw printException(NANP);
	else if (source.find("inf") != std::string::npos) {
		if (source[0] == '+') throw printException(P_INFP);
		else if (source[0] == '-') throw printException(N_INFP);
	}

	double d;
	std::istringstream iss(source);
	iss >> d;
	if (!iss.fail() && iss.eof()) returnDouble = d;
	else throw std::runtime_error("conversion failed");
}

void ScalarConverter::doCast() {
	switch (getFlag()) {
		case CFLAG:
			returnInt = static_cast<int>(returnChar);
			returnFloat = static_cast<float>(returnChar);
			returnDouble = static_cast<double>(returnChar);
			break ;
		case IFLAG:
			returnChar = static_cast<char>(returnInt);
			returnFloat = static_cast<float>(returnInt);
			returnDouble = static_cast<double>(returnInt);
			break ;
		case FFLAG:
			returnChar = static_cast<char>(returnFloat);
			returnInt = static_cast<int>(returnFloat);
			returnDouble = static_cast<double>(returnFloat);
			break ;
		case DFLAG:
			returnChar = static_cast<char>(returnDouble);
			returnInt = static_cast<int>(returnDouble);
			returnFloat = static_cast<float>(returnDouble);
			break ;
	}
}

/* --------------------------------- public --------------------------------- */
void ScalarConverter::checkType(const std::string& source) {
	try {
		// Case literals - Char
		if (source.length() == 1 && !isdigit(source[0])) flag = CFLAG;

		// Case nan, inf, inff
		else if (source == "nanf" || source == "+inff" || source == "-inff") flag = FFLAG;
		else if (source == "nan" || source == "+inf" || source == "-inf") flag = DFLAG;

		// Case ltierals - Float, Double
		else if (source.find('.') != std::string::npos && isFloatOrDouble(source)) {
			if (source[source.length() - 1] == 'f') flag = FFLAG;
			else flag = DFLAG;
		}

		// Case literals - Int
		else if (isAllDigit(source))flag = IFLAG;
		else throw std::runtime_error("Nothing flagged");
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void ScalarConverter::convert(const std::string& source) {
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
		}
		doCast();
	} catch (printException& e) {
		e.exPrint();
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

int ScalarConverter::getFlag() {
	return flag;
}

void ScalarConverter::printValue(std::string input) {
	std::cout << "Char: ";
	{
		// Char value print
		if (returnInt < -128 || returnInt > 127) std::cout << "impossible" << std::endl;
		else if (std::isprint(returnChar)) std::cout << returnChar << std::endl;
		else std::cout << "Non displayable" << std::endl;
	}
	std::cout << "Int: ";
	{
		// Int value print
		if (INT_MIN <= returnDouble && returnDouble <= INT_MAX)
			std::cout << returnInt << std::endl;
		else std::cout << "impossible" << std::endl;
	}
	std::cout << "Float: ";
	{
		// Float value print
		if (8388607 <= returnDouble && returnDouble <= FLT_MAX)
			std::cout << std::fixed << std::setprecision(1) << returnDouble << "f" << std::endl;
		else if (FLT_MIN <= returnDouble && returnDouble <= 8388607)
			std::cout << std::fixed << std::setprecision(1) << returnFloat << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
	std::cout << "Double: ";
	{
		// Double value print
		std::ostringstream convertedDouble;
			convertedDouble << std::fixed << std::setprecision(1) << returnDouble;
		std::string dtos = convertedDouble.str();

			if (dtos == input) std::cout << dtos << std::endl;
		else std::cout << "impossible" << std::endl;
	}
}

/* -------------------------------------------------------------------------- */
/*                               Exception class                              */
/* -------------------------------------------------------------------------- */
printException::printException(int _exType) {
	this->exType = _exType;
}

void printException::exPrint() throw() {
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
bool isAllDigit(const std::string& source) {
	size_t i = 0;
	if (source[0] == '-' || source[0] == '+') ++i;
	for (; i < source.length(); ++i) {
		if (!isdigit(source[i])) return false;
	}
	return true;
}

bool isFloatOrDouble(const std::string& input) {

	// removing 'f' and '.'
	std::string inputWithoutFandDot = input;
	size_t fPosition = input.find('f');
	size_t dotPosition = input.find('.');

	// 'f' exists && 'f' positions at the last of the string && '.' positions before 'f'
	if (fPosition != std::string::npos && input[input.length() - 1] == 'f' && (fPosition - dotPosition) >= 2) {
		inputWithoutFandDot.erase(fPosition, 1);
	}
	if (input.find('.') != std::string::npos && input[0] != '.') { // '.' exists && '.' does not positions at the first of the string
		inputWithoutFandDot.erase(dotPosition, 1);
	}
	if (isAllDigit(inputWithoutFandDot)) return true;

	return false;
}
