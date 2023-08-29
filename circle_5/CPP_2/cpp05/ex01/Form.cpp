#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Form::Form() : name("Default Form"), gradeSigned(0), gradeExecute(0), s(false) {

}

Form::Form(const Form& a) : name(a.name), gradeSigned(a.gradeSigned), gradeExecute(a.gradeExecute), s(false) {

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

	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
const bool Form::getSigned() const {

}

const unsigned int Form::getGradeSigned() const {

}

const unsigned int Form::getGradeExecute() const {

}

void Form::beSigned(const Bureaucrat& b) {

}

void Form::signForm() {

}
