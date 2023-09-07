#include "RobotomyRequestForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
RobotomyRequestForm::RobotomyRequestForm() : name("RobotomyRequestForm"), s(false), gradeSigned(72), gradeExecute(45) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a) : name("RobotomyRequestForm"), gradeSigned(72), gradeExecute(45) {
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
RobotomyRequestForm::~RobotomyRequestForm() {

}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& a) {
	if (this != &a) {
		this->s = a.s;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void RobotomyRequestForm::execute(Bureaucrat const& executor) {

}
