#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat A("Apple", 30);
	Bureaucrat B("Banana", 1);
	Bureaucrat C(B);
	std::cout << A;
	std::cout << B;
	std::cout << "C : " << C;

	try {
		A.decrementGrade(15);
		std::cout << A;
		B.decrementGrade(5);
		std::cout << B;
		B.incrementGrade(6);
		std::cout << B;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	return 0;
}
