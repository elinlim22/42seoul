#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		// Constructor
		Intern();
		Intern(const Intern&);
		// Destructor
		~Intern();
		// Operator overloaded
		Intern& operator= (const Intern& a);
		AForm* makeForm(std::string _name, std::string _target);
};

#endif
