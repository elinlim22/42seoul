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
	if (source.length() == 1 && !isdigit(source[0])) this->flag = CFLAG;
	else {
		std::istringstream iss(source);
		float res;
		if (iss >> res) {
			if (!iss.fail() && source.find('f') != std::string::npos) this->flag = FFLAG;
			else if (!iss.fail()) this->flag = IFLAG;
			else this->flag = DFLAG;
		}
		else throw detectError();
	}
}

int ScalarConverter::getFlag() const {
	return this->flag;
}


char ScalarConverter::convertToChar(const std::string& source) {
	return source[0];
}

int ScalarConverter::convertToInt(const std::string& source) {
	int ret = std::atoi(source.c_str());
	return ret;
}

float ScalarConverter::convertToFloat(const std::string& source) {
	float ret;
	std::istringstream iss(source);
	iss >> ret;
	return ret;
}

double ScalarConverter::convertToDouble(const std::string& source) {
	double ret;
	std::istringstream iss(source);
	iss >> ret;
	return ret;
}

/* -------------------------------------------------------------------------- */
/*                               Exception class                              */
/* -------------------------------------------------------------------------- */
const char* ScalarConverter::detectError::what() const throw() {
	std::cout << "Cannot detect type" << std::endl;
}
