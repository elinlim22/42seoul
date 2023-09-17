#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string target;
	public:
		//Constructors
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm& a);
		//Destructor
		virtual ~RobotomyRequestForm();
		//Operator overloaded
		RobotomyRequestForm& operator= (const RobotomyRequestForm& a);
		//Member functions
		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;
};

#endif
