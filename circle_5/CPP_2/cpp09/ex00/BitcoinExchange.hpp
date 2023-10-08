#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <stdexcept>

class BitcoinExchange {
	private:
		std::map<std::string, float> exchangeRate;
		// Member functions
		bool checkFile(std::string& inputFile, const char* dataFile) const;
		void insertData(std::string& inputFile);
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

// Map 사용
// 01 - Stack 사용
// 02 - List, Deque 사용

