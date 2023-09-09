#include "ScalarConverter.hpp"

char ScalarConverter::convertToChar(const std::string& source) {
	if (source.length() == 1) return source[0];
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
