#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string target;
	public:
		//Constructors
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm& a);
		//Destructor
		~PresidentialPardonForm();
		//Operator overloaded
		PresidentialPardonForm& operator= (const PresidentialPardonForm& a);
		//Member functions
		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;
};

#endif
