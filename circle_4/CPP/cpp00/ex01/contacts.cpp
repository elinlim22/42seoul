#include "contacts.hpp"

void println(std::string str) {
	std::cout << str << std::endl;
};

Contacts::Contacts() {};
Contacts::~Contacts() {};

void Contacts::add() {
	println("===== Please type the following info =====");

	std::cout << "first name : ";
	std::getline(std::cin, first);

	std::cout << "last name : ";
	std::getline(std::cin, last);

	std::cout << "nick name : ";
	std::getline(std::cin, nick);

	std::cout << "phone number : ";
	std::getline(std::cin, pnbr);

	std::cout << "darkest secret : ";
	std::getline(std::cin, secret);

	println("===== Contact added =====");
}

void Contacts::showall() {

}

void Contacts::display() {
	std::cout << "first name : " << first << std::endl;
	std::cout << "last name : " << last << std::endl;
	std::cout << "nick name : " << nick << std::endl;
	std::cout << "phone number : " << pnbr << std::endl;
	std::cout << "darkest secret : " << secret << std::endl;
}
