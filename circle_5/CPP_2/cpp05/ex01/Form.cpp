#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Form::Form() : name("Default Form"), gradeSigned(0), gradeExecute(0), s(false) {

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
	out << a.getName() << " form\n\tsigned: " << a.getSigned() << "\n\tgradeSigned: " << a.getGradeSigned() << "\n\tgradeExecute: " << a.getGradeExecute() << "\n";
	return out;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
const bool Form::getSigned() const {
	return this->s;
}

const unsigned int Form::getGradeSigned() const {
	return this->gradeSigned;
}

const unsigned int Form::getGradeExecute() const {
	return this->gradeExecute;
}

const std::string Form::getName() const {
	return this->name;
}

void Form::beSigned(const Bureaucrat& b) { //점수가 충분히 높으면 Form의 상태를 Signed로 (this->s를 true로)
	try {

	} catch (bool) {
	}
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
