#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool s;
		const unsigned int gradeSigned;
		const unsigned int gradeExecute;
	public:
		//Constructors
		Form();
		Form(std::string _name, unsigned int _gSign, unsigned int _gExec);
		Form(const Form& a);
		//Destructor
		~Form();
		//Operator overloaded
		Form& operator= (const Form& a);
		//Member functions
		void unsign();
		bool getSigned() const;
		unsigned int getGradeSigned() const;
		unsigned int getGradeExecute() const;
		const std::string getName() const;
		void beSigned(const Bureaucrat& b);
		//Exception classes
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};
};

std::ostream& operator<< (std::ostream& out, const Form& a);

#endif
