#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		unsigned int grade;
	public:
		//Constructors
		Bureaucrat();
		Bureaucrat(unsigned int n);
		//Destructor
		virtual ~Bureaucrat();
		//Operator overloaded
		Bureaucrat& operator= (const Bureaucrat& a);
		//Member functions
		const std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade(int n);
		void decrementGrade(int n);
		//Exception functions
		void GradeTooHighException();
		void GradeTooLowException();

};

class Exception : public std::exception {
	public:
		const char* what() const throw();
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a);

#endif
