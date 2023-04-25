#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contacts.hpp"

class PhoneBook {
	private:
		Contacts list[8];
		int count;

	public:
		PhoneBook();
		~PhoneBook();
		void showall();
		void add();
		void search();
};

#endif
