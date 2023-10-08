#include "BitcoinExchange.hpp"

/* -------------------------------------------------------------------------- */
/*                                    OCCF                                    */
/* -------------------------------------------------------------------------- */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& a) {
	*this = a;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& a) {
	if (this != &a) {
		exchangeRate.clear();
		std::map<std::string, float>::const_iterator it;
		for (it = a.exchangeRate.begin(); it != a.exchangeRate.end(); ++it) {
			exchangeRate[it->first] = it->second;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
bool BitcoinExchange::checkFile(std::string& inputFile, const char* dataFile) const {

}

void BitcoinExchange::insertData(std::string& inputFile) {

}

void BitcoinExchange::execute(std::string& inputFile) {
	if (!checkFile(inputFile, "data.csv")) throw std::runtime_error("File open error");

}
