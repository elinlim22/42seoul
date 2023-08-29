#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form : public Bureaucrat {
	private:
		const std::string name;
		bool s;
		const unsigned int gradeSigned;
		const unsigned int gradeExecute;
	public:
		//Constructors
		Form();
		Form(const Form& a);
		//Destructor
		~Form();
		//Operator overloaded
		Form& operator= (const Form& a);
		//Member functions
		const bool getSigned() const;
		const unsigned int getGradeSigned() const;
		const unsigned int getGradeExecute() const;
		void beSigned(const Bureaucrat& b);
		void signForm();
};

#endif
