#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm::ShrubberyCreationForm() : name("ShrubberyCreationForm"), s(false), gradeSigned(25), gradeExecute(5) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a) : name("ShrubberyCreationForm"), gradeSigned(25), gradeExecute(5) {
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& a) {
	if (this != &a) {
		this->s = a.s;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void ShrubberyCreationForm::execute(Bureaucrat const& executor) {

}
