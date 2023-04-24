#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>

class Contacts {
	private:
		std::string first;
		std::string last;
		std::string nick;
		std::string pnbr;
		std::string secret;

	public:
		Contacts();
		~Contacts();
		void add();
		void showall();
		void display();
};

#endif
