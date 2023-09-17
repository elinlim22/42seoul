#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		// Constructors
		Intern();
		Intern(const Intern&);
		// Destructor
		virtual ~Intern();
		// Operator overloaded
		Intern& operator= (const Intern& a);
		// Member function
		AForm* makeForm(std::string _name, std::string _target);
};

#endif
