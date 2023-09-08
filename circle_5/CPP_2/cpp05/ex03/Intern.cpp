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
	std::map<std::string, int> list;
	list["shrubbery creation"] = 1;
	list["robotomy request"] = 2;
	list["presidential pardon"] = 3;

	std::map<std::string, int>::iterator it = list.find(_name);
	try {
		if (it == list.end())
			throw std::runtime_error("Form type not found: " + _name);
		int formType = it->second;
		switch (formType) {
			case 1:
				return new ShrubberyCreationForm(_target);
			case 2:
				return new RobotomyRequestForm(_target);
			case 3:
				return new PresidentialPardonForm(_target);
			default:
				throw std::runtime_error("Unknown error: " + _name);
		}
	} catch (std::runtime_error& e) {
		std::cout << "Intern: Error: " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
