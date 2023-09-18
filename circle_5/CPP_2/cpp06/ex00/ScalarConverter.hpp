#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define CFLAG 1
#define IFLAG 2
#define FFLAG 3
#define DFLAG 4

#define NANP 0 // NaN print
#define P_INFP 1 // Positive infinity print
#define N_INFP 2 // Negative infinity print
#define IMPO 3 // All impossible

#include <iostream>
#include <sstream> // std::istringstream
#include <exception> // std::exception
#include <cctype> // isdigit
#include <iomanip> // std::setprecision
#include <cfloat> // FLT_MAX
#include <climits> // INT_MAX
#include <cstdlib> // std::atoi

class ScalarConverter {
	private:
		static int flag;
		static char returnChar;
		static int returnInt;
		static float returnFloat;
		static double returnDouble;
		static void convertToChar(const std::string& source);
		static void convertToInt(const std::string& source);
		static void convertToFloat(const std::string& source);
		static void convertToDouble(const std::string& source);
		static void doCast();
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter& a);
		// Destructor
		virtual ~ScalarConverter();
		// Operator overloaded
		ScalarConverter& operator= (const ScalarConverter& a);
	public:
		static void checkType(const std::string& source);
		static void convert(const std::string& source);
		static int getFlag();
		static void printValue();

};

bool isAllDigit(const std::string& source);
bool isFloatOrDouble(const std::string& input);

// Exception class
class printException {
	private:
		int exType;
	public:
		printException(int _exType);
		void exPrint() throw();
};

#endif
