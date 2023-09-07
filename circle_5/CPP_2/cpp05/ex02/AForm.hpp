#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string name;
		bool s;
		const unsigned int gradeSigned;
		const unsigned int gradeExecute;
	public:
		//Constructors
		AForm();
		AForm(std::string _name, unsigned int _gSign, unsigned int _gExec);
		AForm(const AForm& a);
		// Destructor
		virtual ~AForm();
		//Operator overloaded
		AForm& operator= (const AForm& a);
		//Member functions
		virtual void unsign();
		virtual bool getSigned() const;
		virtual unsigned int getGradeSigned() const;
		virtual unsigned int getGradeExecute() const;
		virtual const std::string getName() const;
		virtual void beSigned(const Bureaucrat& b);
		virtual void execute(const Bureaucrat& executor) const = 0;
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

std::ostream& operator<< (std::ostream& out, const AForm& a);

#endif
