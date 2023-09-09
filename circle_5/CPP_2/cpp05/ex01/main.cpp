#include "Form.hpp"

int main(void) {
	Bureaucrat A("Adam", 5);
	Bureaucrat B("Ben", 100);
	Form Af("Form A", 5, 5);
	Form Bf("Form B", 100, 100);

	try {
		std::cout << A << std::endl;
		std::cout << Af << std::endl;
		std::cout << B << std::endl;
		std::cout << Bf << std::endl;

		//Case Form got already signed
		A.signForm(Af); // -> Adam signed Form A.
		A.signForm(Af); // -> Adam couldn't sign Form A because The form has been already signed.
		Af.unsign();

		std::cout << "\n\n";
		//Case Ben grade too low
		B.signForm(Af); // -> Ben couldn't sign Form A because Grade is too low.

		std::cout << "\n\n";
		//Case Ben can sign Bf instead
		B.signForm(Bf); // -> Ben signed Form B.

		std::cout << "\n\n";
		//Case Ben got higher grade and can sign Af
		B.setGrade(1);
		B.signForm(Af); // -> Ben signed Form A.
		Af.unsign();

		std::cout << "\n\n";
		//Case setGrade Error
		B.setGrade(0); // -> Error: Grade is too high.
		B.signForm(Af); // Should not be printed
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	return 0;
}
