#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	try {
		Bureaucrat Adam("Adam", 7);
		ShrubberyCreationForm SForm;
		RobotomyRequestForm RForm;
		PresidentialPardonForm PForm;

		std::cout << Adam << std::endl;
		std::cout << SForm << std::endl;
		std::cout << RForm << std::endl;
		std::cout << PForm << std::endl;


		Adam.signForm(SForm);
		Adam.signForm(RForm);
		Adam.signForm(PForm);

		Adam.executeForm(SForm);
		Adam.executeForm(RForm);
		Adam.executeForm(PForm);
	} catch (std::exception& e) {
		std::cout << "Input error\n";
	}

	return 0;
}
