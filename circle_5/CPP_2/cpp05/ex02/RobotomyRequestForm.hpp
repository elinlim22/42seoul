#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string name;
		bool s;
		const unsigned int gradeSigned;
		const unsigned int gradeExecute;
	public:
		//Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& a);
		//Destructor
		~RobotomyRequestForm();
		//Operator overloaded
		RobotomyRequestForm& operator= (const RobotomyRequestForm& a);
		//Member functions
		void execute(Bureaucrat const& executor);
};

#endif
