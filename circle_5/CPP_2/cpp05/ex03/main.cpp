#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
	Bureaucrat A("Adam", 10);
	AForm* rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");

	A.signForm(*rrf);
	A.executeForm(*rrf);

	std::cout << *rrf << std::endl;

	delete rrf;
	return 0;
}
