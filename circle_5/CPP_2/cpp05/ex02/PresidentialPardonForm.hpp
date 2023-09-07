#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
	// 	const std::string name;
		bool s;
	// 	const unsigned int gradeSigned;
	// 	const unsigned int gradeExecute;
	public:
		//Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& a);
		//Destructor
		~PresidentialPardonForm();
		//Operator overloaded
		PresidentialPardonForm& operator= (const PresidentialPardonForm& a);
		//Member functions
		void execute(const Bureaucrat& executor) const;
};

#endif
