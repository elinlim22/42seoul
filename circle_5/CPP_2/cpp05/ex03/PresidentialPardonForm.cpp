#include "PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a) : AForm("PresidentialPardonForm", 145, 137) {
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
PresidentialPardonForm::~PresidentialPardonForm() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& a) {
	if (this != &a) {
		this->s = a.s;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	else if (this->getSigned() == UNSIGNED) throw std::runtime_error("The form has not been signed yet.\n");
}
