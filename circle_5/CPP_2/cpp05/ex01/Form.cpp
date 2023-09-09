#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Form::Form() : name("Default Form"), s(false), gradeSigned(10), gradeExecute(10) {

}

Form::Form(std::string _name, unsigned int _gSign, unsigned int _gExec) : name(_name), s(false), gradeSigned(_gSign), gradeExecute(_gExec) {

}

Form::Form(const Form& a) : name(a.name), gradeSigned(a.gradeSigned), gradeExecute(a.gradeExecute) {
	this->s = a.s;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Form::~Form() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Form& Form::operator= (const Form& a) {
	if (this != &a) {
		this->s = a.s;
	}
	return *this;
}

std::ostream& operator<< (std::ostream& out, const Form& a) {
	out << a.getName() << " form\n\tsigned: " << a.getSigned() << "\n\tgradeSigned: " << a.getGradeSigned() << "\n\tgradeExecute: " << a.getGradeExecute();
	return out;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void Form::unsign() {
	this->s = false;
}

bool Form::getSigned() const {
	return this->s;
}

unsigned int Form::getGradeSigned() const {
	return this->gradeSigned;
}

unsigned int Form::getGradeExecute() const {
	return this->gradeExecute;
}

const std::string Form::getName() const {
	return this->name;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= this->getGradeSigned() && !this->s) this->s = SIGNED;
	else if (!this->s) throw GradeTooLowException();
	else throw std::runtime_error("The form has been already signed.\n");
}

/* -------------------------------------------------------------------------- */
/*                              Exception classes                             */
/* -------------------------------------------------------------------------- */
const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high.\n");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low.\n");
}
