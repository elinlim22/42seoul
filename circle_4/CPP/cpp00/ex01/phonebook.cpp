/*
	phonebook
		1. array of contacts
		2. max 8 contacts : if 9th, replace 1st
		3. dynamic allocation forbidden
	class
		1. phonebook class
		2. contacts class
	commands
		1. ADD
		2. SEARCH
			- 4 columns(index, first, last, nickname) with 10 width separated by "|"
			- if longer than 10 characters, the last displayable character must be replaced by a "."
		3. EXIT
		4. any other input is discarded

		getline() 이용
*/

#include "phonebook.hpp"

PhoneBook::PhoneBook() : count(-1) {};
PhoneBook::~PhoneBook() {};

void PhoneBook::add() {
	count++;
	if (count == 8) count = 0;
	list[count].add();
};

void PhoneBook::showall() {
	for (int i = 0; i < 8; i++) {
		list[i].showall(i);
	}
}

void PhoneBook::search() {
	std::cout << "===== List =====" << std::endl;
	showall();
	std::cout << "===== Please enter the index number =====" << std::endl << "index : ";
	std::string temp;
	int i;
	while (std::getline(std::cin, temp)) {
		i = std::atoi(temp.c_str());
		if (temp.size() >= 2 || i < 1 || i > 8)
			std::cout << "Wrong index: index arrange [1 ~ 8]" << std::endl;
		else break;
	}
	list[i - 1].display();
};

int main() {
	PhoneBook pb;
	std::string cmd;
	std::cout << "Welcome" << std::endl;

	while (1) {
		std::cout << std::endl << "Please type a command" << std::endl << ">> ";
		std::getline(std::cin, cmd);
		std::cout << std::endl;
		if (!cmd.compare("EXIT")) break ;
		else if (!cmd.compare("ADD")) pb.add();
		else if (!cmd.compare("SEARCH")) pb.search();
		else std::cout << "Wrong command: commands [ADD, SEARCH, EXIT]";
	}
	std::cout << "Dobby is free!" << std::endl;

	return 0;
}
