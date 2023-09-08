#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		// const std::string name;
		bool s;
		// const unsigned int gradeSigned;
		// const unsigned int gradeExecute;
	public:
		//Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& a);
		//Destructor
		~ShrubberyCreationForm();
		//Operator overloaded
		ShrubberyCreationForm& operator= (const ShrubberyCreationForm& a);
		//Member functions
		void execute(const Bureaucrat& executor) const;
};

#endif
