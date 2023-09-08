#include "Intern.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Intern::Intern() {}

Intern::Intern(const Intern& a) {
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Intern::~Intern() {}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Intern& Intern::operator= (const Intern&) {
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                               Member function                              */
/* -------------------------------------------------------------------------- */
AForm* Intern::makeForm(std::string _name, std::string _target) {
	std::string list[4];
	list[0] = "shrubbery creation";
	list[1] = "robotomy request";
	list[2] = "presidential pardon";
	list[3] = "";

	int it = 0;
	try {
		for (; it < 4; it++)
			if (list[it] == _name) break ;
		switch (it) {
			case 0:
				return new ShrubberyCreationForm(_target);
			case 1:
				return new RobotomyRequestForm(_target);
			case 2:
				return new PresidentialPardonForm(_target);
			default:
				throw std::runtime_error("Form type not found: " + _name);
		}
	} catch (std::runtime_error& e) {
		std::cout << "Intern: Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
