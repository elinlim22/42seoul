#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ScalarConverter::ScalarConverter() : flag(0) {

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
	}
	return *this;
}
/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
// void ScalarConverter::checkPrint(const std::string& source) const {
// 	try {
// 		if (source == list[0]) throw Nonprintable();
// 		else if (source == list[1] || source == list[2] || source == list[4] || source == list[5]) throw InfinityPrint();
// 		else if (source == list[3] || source == list[6]) throw NanPrint();
// 	} catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// }

void ScalarConverter::checkType(const std::string& source) {
	if (source.length() == 1 && !isdigit(source[0])) this->flag = CFLAG;
	else {
		if (source.find('.') != std::string::npos) {
			if (source.find('f') != std::string::npos) this->flag = FFLAG;
			else this->flag = DFLAG;
		} else this->flag = IFLAG;
	}

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
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << "\n";
		std::exit(EXIT_FAILURE);
	}
}

int ScalarConverter::getFlag() const {
	return this->flag;
}


void ScalarConverter::convertToChar(const std::string& source) {
	this->returnChar = source[0];
	// throw : x
	this->returnInt = static_cast<int>(returnChar);
	this->returnFloat = static_cast<float>(returnChar);
	this->returnDouble = static_cast<double>(returnChar);
}

void ScalarConverter::convertToInt(const std::string& source) {
	this->returnInt = std::atoi(source.c_str());
	// throw : x
	if (returnInt == 0) throw Nonprintable();
	else this->returnChar = static_cast<char>(returnInt);
	this->returnFloat = static_cast<float>(returnInt);
	this->returnDouble = static_cast<double>(returnInt);
}

void ScalarConverter::convertToFloat(const std::string& source) {
	if (source == "nan") throw NanPrint();
	else if (source == "+inff" || source == "-inff") throw InfinityPrint();
	float ret;

	std::string strWithoutF = source;
	size_t fPosition = strWithoutF.find('f');
	if (fPosition != std::string::npos)	strWithoutF.erase(fPosition, 1);

	std::istringstream iss(strWithoutF);
	iss >> ret;
	this->returnFloat = ret;
	// throw : Infinity, nanf --> 적용시 함수 빠져나가는데..
	this->returnInt = static_cast<int>(returnFloat);
	this->returnDouble = static_cast<double>(returnFloat);
	if (returnInt == 0) throw Nonprintable(); //?
	else this->returnChar = static_cast<char>(returnInt);
}

void ScalarConverter::convertToDouble(const std::string& source) {
	double ret;
	std::istringstream iss(source);
	iss >> ret;
	this->returnDouble = ret;
	// throw : Infinity, nan --> 함수 빠져나가는 문제 어떡함
	this->returnInt = static_cast<int>(returnDouble);
	this->returnFloat = static_cast<float>(returnDouble);
	if (returnInt == 0) throw Nonprintable(); //?
	else this->returnChar = static_cast<char>(returnInt);
}

void ScalarConverter::printValue() const {
	std::cout << "Char: " << this->returnChar << std::endl;
	std::cout << "Int: " << this->returnInt << std::endl;
	std::cout << "Float: " << this->returnFloat << std::endl;
	std::cout << "Double: " << this->returnDouble << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Exception class                              */
/* -------------------------------------------------------------------------- */
const char* ScalarConverter::detectError::what() const throw() {
	return ("Cannot detect type");
}

const char* ScalarConverter::Nonprintable::what() const throw() {
	return ("Non displayable");
}

const char* ScalarConverter::InfinityPrint::what() const throw() {
	return ("Infinity");
}

const char* ScalarConverter::NanPrint::what() const throw() {
	return ("Impossible");
}

