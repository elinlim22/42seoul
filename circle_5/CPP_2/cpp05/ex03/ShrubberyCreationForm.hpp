#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		//Constructors
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm& a);
		//Destructor
		~ShrubberyCreationForm();
		//Operator overloaded
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& a);
		//Member functions
		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;
};

#endif
