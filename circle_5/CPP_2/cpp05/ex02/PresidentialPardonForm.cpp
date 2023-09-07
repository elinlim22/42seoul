#include "PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
PresidentialPardonForm::PresidentialPardonForm() : name("PresidentialPardonForm"), s(false), gradeSigned(145), gradeExecute(137) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a) : name("PresidentialPardonForm"), gradeSigned(145), gradeExecute(137) {
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
void PresidentialPardonForm::execute(Bureaucrat const& executor) {

}
