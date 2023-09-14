#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define CFLAG 1
#define IFLAG 2
#define FFLAG 3
#define DFLAG 4

#define NANP 0 // NaN print
#define P_INFP 1 // Positive infinity print
#define N_INFP 2 // Negative infinity print

#include <iostream>
#include <sstream> // std::istringstream
#include <exception> // std::exception
#include <cctype> // isdigit
#include <iomanip> // std::setprecision
#include <cfloat> // FLT_MAX
#include <cstdlib> // std::atoi

class ScalarConverter {
	private:
		int flag;
		char returnChar;
		int returnInt;
		float returnFloat;
		double returnDouble;
		void convertToChar(const std::string& source);
		void convertToInt(const std::string& source);
		void convertToFloat(const std::string& source);
		void convertToDouble(const std::string& source);
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter& a);
		// Destructor
		virtual ~ScalarConverter();
		// Operator overloaded
		ScalarConverter& operator= (const ScalarConverter& a);
		// Member functions
		void checkType(const std::string& source);
		void doCast(const std::string& source);
		int getFlag() const;
		void printValue() const;
		// Exception class
		class printException : public std::exception {
			private:
				int exType;
			public:
				printException(int _exType);
				void exPrint() throw();
		};
};

bool isInt(const std::string& source);
bool isFloatOrDouble(const std::string& input);

#endif
