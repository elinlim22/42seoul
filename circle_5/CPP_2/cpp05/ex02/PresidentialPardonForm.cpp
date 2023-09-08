#include "PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 145, 137) {
	this->target = _target;
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
		this->target = a.target;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
std::string PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	else if (this->getSigned() == UNSIGNED) throw std::runtime_error("The form has not been signed yet.\n");
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
