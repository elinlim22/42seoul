#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {
	public:
		static char convertToChar(const std::string& source);
		static int convertToInt(const std::string& source);
		static float convertToFloat(const std::string& source);
		static double convertToDouble(const std::string& source);
};

#endif
