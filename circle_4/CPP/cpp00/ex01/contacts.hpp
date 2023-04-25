#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>
#include <iomanip>

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
		void tell(std::string *dest);
		void add();
		void showall(int i);
		void display();
};

#endif
