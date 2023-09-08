#include "RobotomyRequestForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a) : AForm("RobotomyRequestForm", 72, 45) {
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
		this->target = a.target;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
std::string RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	else if (this->getSigned() == UNSIGNED) throw std::runtime_error("The form has not been signed yet.\n");
	std::cout << "Vroom-vroom!!!!" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(0)));
	int rd = std::rand() % 100 + 1;
	if (rd >= 50) std::cout << this->getTarget() << " has been successfully robotomized.\n";
	else std::cout << this->getTarget() << "has been failed to be robotomized.\n";
}
