#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat A("A", 10);
	std::cout << A << std::endl;

	Bureaucrat B(A);
	std::cout << B << std::endl;

	try {
		A.decrementGrade(15);
		std::cout << A << std::endl;
		B.decrementGrade(5);
		std::cout << B << std::endl;
		B.incrementGrade(6);
		std::cout << B << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	return 0;
}
