#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ScalarConverter::ScalarConverter() : flag(0) {
	list[0] = "0";
	list[1] = "-inff";
	list[2] = "+inff";
	list[3] = "nanf";
	list[4] = "-inf";
	list[5] = "+inf";
	list[6] = "nan";
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
void ScalarConverter::checkPrint(const std::string& source) const {
	// switch ()
}

void ScalarConverter::checkType(const std::string& source) {
	if (source.length() == 1 && !isdigit(source[0])) this->flag = CFLAG;
	else {
		if (source.find('.') != std::string::npos) {
			if (source.find('f') != std::string::npos) this->flag = FFLAG;
			else this->flag = DFLAG;
		} else this->flag = IFLAG;
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
	std::string strWithoutF = source;
	size_t fPosition = strWithoutF.find('f');
	if (fPosition != std::string::npos)	strWithoutF.erase(fPosition, 1);
	std::istringstream iss(strWithoutF);
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
	return ("Cannot detect type");
}
