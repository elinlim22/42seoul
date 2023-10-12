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
/* --------------------------------- Private -------------------------------- */
void BitcoinExchange::insertData(std::ifstream& dataBase) {
	try {
		std::string line;
		std::string date;
		float value;

		std::getline(dataBase, line);
		while (std::getline(dataBase, line)) {
			splitIntoStrAndFlt(line, ",", date, value);
			exchangeRate[date] = value;
		}
	} catch (std::runtime_error& e) { // data.csv parse error
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void BitcoinExchange::parseInput(std::string& str) const {
	try {
		std::string inputDate;
		float inputPrice;

		splitIntoStrAndFlt(str, " | ", inputDate, inputPrice);

		std::map<std::string, float>::const_iterator it = exchangeRate.lower_bound(checkDate(inputDate));
		if (it == exchangeRate.end()) throw printError(NOKEY);
		printData(inputDate, it->second, checkPrice(inputPrice));
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

std::string BitcoinExchange::checkDate(std::string& str) const {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	if (splitIntoYMD(str, year, month, day)) { // split and check
		if (month == 2) {
			if (!IsLeapYear(year) && day <= 28) return str;
			else if (IsLeapYear(year) && day <= 29) return str;
		} else {
			if (day <= 31 && !(month == 4 || month == 6 || month == 9 || month == 11)) return str;
			else if (day <= 30 && (month == 4 || month == 6 || month == 9 || month == 11)) return str;
		}
	}
	std::string errorString = "bad input => " + str;
	throw std::runtime_error(errorString);
}

float BitcoinExchange::checkPrice(float val) const{
	if (val < 0) throw printError(WRONGVALUE_L);
	else if (val > 1000) throw printError(WRONGVALUE_H);
	return val;
}

void BitcoinExchange::printData(std::string& date, float value, float price) const {
	std::cout << date << " => " << price << " = " << price * value << std::endl;
}

void BitcoinExchange::splitIntoStrAndFlt(std::string& line, const char* del, std::string& front, float& back) const {
	size_t pos = line.find(del);
	if (pos != std::string::npos) {
		front = line.substr(0, pos);
		std::istringstream iss(line.substr(pos + std::string(del).length()));
		iss >> back;
	} else {
		std::string errorString = "bad input => " + line;
		throw std::runtime_error(errorString);
	}
}

bool BitcoinExchange::splitIntoYMD(std::string& date, unsigned int& year, unsigned int& month, unsigned int& day) const {
	std::istringstream iss(date);
	char c;
	iss >> year >> c >> month >> c >> day;
	if (year < 1 || 9999 < year || month < 1 || 12 < month || day < 1 || 31 < day) return false;
	return true;
}

bool BitcoinExchange::IsLeapYear(int year) const {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}

/* --------------------------------- Public --------------------------------- */
void BitcoinExchange::execute(std::string& _inputFile) {
	std::ifstream inputFile(_inputFile);
	std::ifstream dataBase("data.csv");
	if (!inputFile.is_open() || !dataBase.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	insertData(dataBase);
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line)) {
		parseInput(line);
	}
	inputFile.close();
	dataBase.close();
}

/* -------------------------------------------------------------------------- */
/*                               Exception class                              */
/* -------------------------------------------------------------------------- */
BitcoinExchange::printError::printError(int _flag) {
	flag = _flag;
}

const char* BitcoinExchange::printError::what() const throw() {
	switch(flag) {
		case NOKEY:
			return ("no key has been found in DB.");
		case WRONGVALUE_L:
			return ("not a positive number.");
		case WRONGVALUE_H:
			return ("too large number.");
		default:
			return ("Wrong exception.");
	}
}
