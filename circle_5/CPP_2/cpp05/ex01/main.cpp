#include "Form.hpp"

int main(void) {
	Bureaucrat A("Adam", 5);
	Bureaucrat B("Ben", 100);
	Form Af("Form A", 5, 5);
	Form Bf("Form B", 100, 100);

	try {
		//Case Form got already signed
		A.signForm(Af);
		A.signForm(Af);
		Af.unsign();

		std::cout << "\n\n";
		//Case Ben grade too low
		B.signForm(Af);

		std::cout << "\n\n";
		//Case Ben can sign Bf instead
		B.signForm(Bf);

		std::cout << "\n\n";
		//Case Ben got higher grade and can sign Af
		B.setGrade(1);
		B.signForm(Af);
		Af.unsign();

		std::cout << "\n\n";
		//Case setGrade Error
		B.setGrade(0);
		B.signForm(Af); ///Should not be printed?
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what();
	}
	return 0;
}
