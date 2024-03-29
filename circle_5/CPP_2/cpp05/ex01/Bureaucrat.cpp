#include "Bureaucrat.hpp"
#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
}

Bureaucrat::Bureaucrat(unsigned int _grade) : name("Default") {
	try {
		this->setGrade(_grade);
	} catch (std::exception& e) {
		std::cout << this->name << ": Input Error: " << e.what();
		std::exit(EXIT_FAILURE);
	}
}

Bureaucrat::Bureaucrat(const std::string _name) : name(_name), grade(1) {
}

Bureaucrat::Bureaucrat(const std::string _name, unsigned int _grade) : name(_name) {
	try {
		this->setGrade(_grade);
	} catch (std::exception& e) {
		std::cout << this->name << ": Input Error: " << e.what();
		std::exit(EXIT_FAILURE);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& a) : name(a.name) {
	*this = a;
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
		this->grade = a.grade;
	}
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a) {
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return out;
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

void Bureaucrat::setGrade(unsigned int n) {
	if (n < 1) throw GradeTooHighException();
	else if (n > 150) throw GradeTooLowException();
	this->grade = n;
}

void Bureaucrat::incrementGrade(unsigned int n) {
	if (this->grade <= n) {
		throw GradeTooHighException();
	} else {
		this->grade -= n;
	}
}

void Bureaucrat::decrementGrade(unsigned int n) {
	if (150 - this->grade < n) {
		throw GradeTooLowException();
	} else {
		this->grade += n;
	}
}

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << ".\n";
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what();
	}
}
/* -------------------------------------------------------------------------- */
/*                              Exception classes                             */
/* -------------------------------------------------------------------------- */
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low.\n");
}

