#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	try {
		Bureaucrat Adam("Adam", 1);
		// ShrubberyCreationForm SForm("Tree");
		// RobotomyRequestForm RForm("타겟");
		PresidentialPardonForm PForm("Target");

		std::cout << Adam << std::endl;
		// std::cout << SForm << std::endl;
		// std::cout << RForm << std::endl;
		std::cout << PForm << std::endl;


		// Adam.signForm(SForm);
		// Adam.signForm(RForm);
		Adam.signForm(PForm);

		// Adam.executeForm(SForm);
		// Adam.executeForm(RForm);
		Adam.executeForm(PForm);
	} catch (std::exception& e) {
		std::cout << "Input error\n";
	}

	return 0;
}
