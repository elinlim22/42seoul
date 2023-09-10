#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define CFLAG (1 << 0)
#define IFLAG (1 << 1)
#define FFLAG (1 << 2)
#define DFLAG (1 << 3)

#include <iostream>
#include <sstream>
#include <exception>
#include <cctype>

class ScalarConverter {
	private:
		int flag;
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter& a);
		// Destructor
		~ScalarConverter();
		// Operator overloaded
		ScalarConverter& operator= (const ScalarConverter& a);
		// Member functions
		void checkType(const std::string& source);
		int getFlag() const;
		static char convertToChar(const std::string& source);
		static int convertToInt(const std::string& source);
		static float convertToFloat(const std::string& source);
		static double convertToDouble(const std::string& source);
		// Exception class
		class detectError : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif
