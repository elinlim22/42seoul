#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 25, 5) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& a) : AForm("ShrubberyCreationForm", 25, 5) {
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
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	else if (this->getSigned() == UNSIGNED) throw std::runtime_error("The form has not been signed yet.\n");
}
