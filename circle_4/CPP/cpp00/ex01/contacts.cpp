#include "contacts.hpp"

void println(std::string str) {
	std::cout << str << std::endl;
};

Contacts::Contacts() {};
Contacts::~Contacts() {};

void Contacts::tell(std::string *dest) {
	while (!std::getline(std::cin, *dest) && (*dest).empty()) {
		std::cout << "Type something!" << std::endl;
		std::cin.clear();
	}
} /////////////////////////////////////////////////////////////////반복된 null입력에 반응 못함 정신못차림

void Contacts::add() {
	println("===== Please type the following info =====");

	std::cout << "first name : ";
	tell(&first);

	std::cout << "last name : ";
	std::getline(std::cin, last);
	tell(&last);

	std::cout << "nick name : ";
	std::getline(std::cin, nick);
	tell(&nick);

	std::cout << "phone number : ";
	std::getline(std::cin, pnbr);
	tell(&pnbr);

	std::cout << "darkest secret : ";
	std::getline(std::cin, secret);
	tell(&secret);

	println("===== Contact added =====");
}

void Contacts::showall(int i) {
	std::string tmp;
	std::cout << '|';
	std::cout << std::setw(10) << i + 1 << '|';
	if (first.length() > 10) {
		tmp = first.substr(0, 9) + '.';
		std::cout << std::setw(10) << tmp << '|';
	} else std::cout << std::setw(10) << first << '|';
	if (last.length() > 10) {
		tmp = last.substr(0, 9) + '.';
		std::cout << std::setw(10) << tmp << '|';
	} else std::cout << std::setw(10) << last << '|';
	if (nick.length() > 10) {
		tmp = nick.substr(0, 9) + '.';
		std::cout << std::setw(10) << tmp << '|' << std::endl;
	} else std::cout << std::setw(10) << nick << '|' << std::endl;
}

void Contacts::display() {
	std::cout << "first name : " << first << std::endl;
	std::cout << "last name : " << last << std::endl;
	std::cout << "nick name : " << nick << std::endl;
	std::cout << "phone number : " << pnbr << std::endl;
	std::cout << "darkest secret : " << secret << std::endl;
	std::cout << "===== SEARCH ended =====" << std::endl;
}
