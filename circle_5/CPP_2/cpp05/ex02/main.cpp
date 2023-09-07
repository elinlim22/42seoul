#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat Adam("Adam", 20);
	ShrubberyCreationForm Form;

	// std::cout << Form << std::endl;
	Adam.signForm(Form);
	// std::cout << Adam << std::endl;
	// std::cout << Form << std::endl;

	Adam.executeForm(Form);
	// std::cout << Adam << std::endl;
	// std::cout << Form << std::endl;


	return 0;
}
