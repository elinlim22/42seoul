#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <cstdlib>

#define NOKEY 0
#define WRONGVALUE_L 1
#define WRONGVALUE_H 2

class BitcoinExchange {
	private:
		std::map<std::string, float> exchangeRate;
		// Member functions
		void insertData(std::ifstream& dataBase);
		void parseInput(std::string& line) const;
		std::string checkDate(std::string& str) const;
		float checkPrice(float val) const;
		void printData(std::string& date, float value, float price) const;
		void splitIntoStrAndFlt(std::string& line, const char* del, std::string& front, float& back) const;
		bool splitIntoYMD(std::string& date, unsigned int& year, unsigned int& month, unsigned int& day) const;
		bool IsLeapYear(int year) const;
		// Exception class
		class printError : public std::exception {
			private:
				int flag;
			public:
				printError(int _flag);
				const char* what() const throw();
		};
	public:
		// OCCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& a);
		BitcoinExchange& operator= (const BitcoinExchange& a);
		virtual ~BitcoinExchange();
		// Member function
		void execute(std::string& inputFile);
};


#endif


