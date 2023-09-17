#include "AForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
AForm::AForm() : name("Default AForm"), s(false), gradeSigned(10), gradeExecute(10) {

}

AForm::AForm(std::string _name, unsigned int _gSign, unsigned int _gExec) : name(_name), s(false), gradeSigned(_gSign), gradeExecute(_gExec) {

}

AForm::AForm(const AForm& a) : name(a.name), gradeSigned(a.gradeSigned), gradeExecute(a.gradeExecute) {
	this->s = a.s;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
AForm::~AForm() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
AForm& AForm::operator= (const AForm& a) {
	if (this != &a) {
		this->s = a.s;
	}
	return *this;
}

std::ostream& operator<< (std::ostream& out, const AForm& a) {
	out << a.getName() << " form\n\tsigned: " << a.getSigned() << "\n\tgradeSigned: " << a.getGradeSigned() << "\n\tgradeExecute: " << a.getGradeExecute() << "\n\ttarget: " << a.getTarget();
	return out;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
bool AForm::getSigned() const {
	return this->s;
}

void AForm::unsign() {
	this->s = false;
}

unsigned int AForm::getGradeSigned() const {
	return this->gradeSigned;
}

unsigned int AForm::getGradeExecute() const {
	return this->gradeExecute;
}

const std::string AForm::getName() const {
	return this->name;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= this->getGradeSigned() && this->s == UNSIGNED) this->s = SIGNED;
	else if (this->s == UNSIGNED) throw GradeTooLowException();
	else throw std::runtime_error("The form has been already signed.\n");
}

/* -------------------------------------------------------------------------- */
/*                              Exception classes                             */
/* -------------------------------------------------------------------------- */
const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high.\n");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low.\n");
}
