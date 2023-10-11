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
		std::string front;
		float back;

		while (std::getline(dataBase, line)) {
			splitIntoStrAndFlt(line, ",", front, back);
			exchangeRate[front] = back;
		}
	} catch (std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void BitcoinExchange::parseInput(std::string& str) const {
	try {
		std::string front;
		float back;

		splitIntoStrAndFlt(str, " | ", front, back);

		std::map<std::string, float>::const_iterator it = exchangeRate.find(checkDate(front)); /// 안됨
		if (it == exchangeRate.end()) {
			// 날짜가 DB에 없으면
			// 가장 가까운 값으로 설정
			throw printError(3); //수정
		}
		printData(it, checkValue(back));
	}
	//  catch (std::runtime_error& e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// 	std::exit(EXIT_FAILURE);
	// }
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

std::string BitcoinExchange::checkDate(std::string& str) const {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	if (splitIntoYMD(str, year, month, day)) {
		if (month == 2) {
			if (!IsLeapYear(year) && day <= 28) return str;
			else if (IsLeapYear(year) && day <= 29) return str;
		} else {
			if (day == 31 && !(month == 4 || month == 6 || month == 9 || month == 11)) return str;
			else if (day <= 30 && (month == 4 || month == 6 || month == 9 || month == 11)) return str;
		} // 아닐때 else로 넘어가나?
		return str;
	}
	// throw printError(WRONGKEY);
	std::string errorString = "bad input => " + str;
	throw std::runtime_error(errorString);
}

float BitcoinExchange::checkValue(float val) const{
	if (val < 0) throw printError(WRONGVALUE_L);
	else if (val > 1000) throw printError(WRONGVALUE_H);
	return val;
}

void BitcoinExchange::printData(std::map<std::string, float>::const_iterator it, float price) const {
	std::cout << it->first << " => " << price << " = " << price * it->second << std::endl;
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
		case WRONGKEY:
			return ("bad input");
		case WRONGVALUE_L:
			return ("not a positive number.");
		case WRONGVALUE_H:
			return ("too large number.");
		default:
			return ("Wrong exception.");
	}
}

/* -------------------------------------------------------------------------- */
/*                              Utility function                              */
/* -------------------------------------------------------------------------- */
void splitIntoStrAndFlt(std::string& line, const char* del, std::string& front, float& back) {
	size_t pos = line.find(del);
	if (pos != std::string::npos) {
		front = line.substr(0, pos);
		std::istringstream iss(line.substr(pos + std::string(del).length()));
		iss >> back;
	// } else throw std::runtime_error("Parse error");
	// } else throw BitcoinExchange::printError(WRONGKEY);
	} else {
		std::string errorString = "bad input => " + line;
		throw std::runtime_error(errorString);
	}

	// } else throw BitcoinExchange::printError(WRONG)
};

bool splitIntoYMD(std::string& date, unsigned int& year, unsigned int& month, unsigned int& day) {
	std::istringstream iss(date);
	char c;
	iss >> year >> c >> month >> c >> day;
	if (year < 1 || 9999 < year || month < 1 || 12 < month || day < 1 || 31 < day) return false;
	return true;
}

bool IsLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	} else {
		return false;
	}
}
