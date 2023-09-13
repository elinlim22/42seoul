#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define CFLAG (1 << 0)
#define IFLAG (1 << 1)
#define FFLAG (1 << 2)
#define DFLAG (1 << 3)

#define NANP 0
#define P_INFP 1
#define N_INFP 2

#include <iostream>
#include <sstream>
#include <exception>
#include <cctype>
#include <iomanip>

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
		~ScalarConverter();
		// Operator overloaded
		ScalarConverter& operator= (const ScalarConverter& a);
		// Member functions
		// void checkPrint(const std::string& source) const;
		void checkType(const std::string& source);
		void doCast(const std::string& source);
		int getFlag() const;
		void printValue() const;
		// Exception class
		// class detectError : public std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };
		// class Nonprintable : public std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };
		// class InfinityPrint : public std::exception {
		// 	public:
		// 		void
		// 		// const char* what() const throw();
		// };
		class printException : public std::exception {
			public:
				void ePrint(int exType) throw();
				// const char* what() const throw();
		};
};

#endif
