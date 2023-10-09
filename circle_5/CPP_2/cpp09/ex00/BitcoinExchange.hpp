#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <fstream>

#define WRONGKEY 0
#define WRONGVALUE_L 1
#define WRONGVALUE_H 2

class BitcoinExchange {
	private:
		std::map<std::string, float> exchangeRate;
		// Member functions
		bool checkFile(std::string& inputFile, const char* dataFile) const;
		void insertData(std::ifstream& dataBase);
		void parseData(std::string& line) const;
		std::string checkDate(std::string& str) const;
		float checkValue(float val) const;
		void printData(std::map<std::string, float>::const_iterator it, float price) const;
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

void splitIntoStrAndFlt(std::string& line, const char* del, std::string& front, float& back);

#endif

// Map 사용
// 01 - Stack 사용
// 02 - List, Deque 사용

