#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
}

Bureaucrat::Bureaucrat(unsigned int n) : name("Default"), grade(n) {
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Bureaucrat::~Bureaucrat() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Bureaucrat& Bureaucrat::operator= (const Bureaucrat& a) {
	if (this != &a) {
		this->name = a.name;
		this->grade = a.grade; //////////////////////
	}
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a) {

}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
const std::string Bureaucrat::getName() const {
	return (this->name);
}

unsigned int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::incrementGrade(int n) {

}

void Bureaucrat::decrementGrade(int n) {

}

/* -------------------------------------------------------------------------- */
/*                             Exception functions                            */
/* -------------------------------------------------------------------------- */
void Bureaucrat::GradeTooHighException() {
	// std::cout << "Exception: Grade is too high\n";
}

void Bureaucrat::GradeTooLowException() {
	// std::cout << "Exception: Grade is too low\n";
}

