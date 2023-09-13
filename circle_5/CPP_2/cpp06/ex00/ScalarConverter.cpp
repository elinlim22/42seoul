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
void ScalarConverter::checkType(const std::string& source) {
	if (source.find("nan") != std::string::npos) {
		if (source[source.length() - 1] == 'f') this->flag = FFLAG;
		else this->flag = DFLAG;
	}
	else if (source.length() == 1 && !isdigit(source[0])) this->flag = CFLAG;
	else {
		if (source.find('.') != std::string::npos || source.find("inf") != std::string::npos) {
			if (source[source.length() - 1] == 'f') this->flag = FFLAG;
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
	} catch (ScalarConverter::printException& e) {
		e.ePrint();
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
	if (source == "nanf") throw printException();
	else if (source.find("inff") != std::string::npos) throw InfinityPrint();
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
	this->returnChar = static_cast<char>(returnInt);
}

void ScalarConverter::convertToDouble(const std::string& source) {
	if (source == "nan") throw printException();
	double ret;
	std::istringstream iss(source);
	iss >> ret;
	this->returnDouble = ret;
	// throw : Infinity, nan --> 함수 빠져나가는 문제 어떡함
	this->returnInt = static_cast<int>(returnDouble);
	this->returnFloat = static_cast<float>(returnDouble);
	this->returnChar = static_cast<char>(returnInt);
}

void ScalarConverter::printValue() const {
	if (std::isprint(this->returnChar)) std::cout << "Char: " << this->returnChar << std::endl;
	else std::cout << "Char: Non displayable" << std::endl;
	std::cout << "Int: " << this->returnInt << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "Float: " << this->returnFloat << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "Double: " << this->returnDouble << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Exception class                              */
/* -------------------------------------------------------------------------- */
// const char* ScalarConverter::detectError::what() const throw() {
// 	return ("Cannot detect type");
// }

// const char* ScalarConverter::Nonprintable::what() const throw() {
// 	return ("Non displayable");
// }

// const char* ScalarConverter::InfinityPrint::what() const throw() {
// 	return ("Infinity");
// }

// const char* ScalarConverter::printException::what() const throw() {
// 	return ("Impossible");
// }

void ScalarConverter::printException::ePrint(int exType) throw() {
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: nanf" << std::endl;
	std::cout << "Double: nan" << std::endl;
	std::exit(EXIT_FAILURE);
}

