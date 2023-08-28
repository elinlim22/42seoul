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
		Bureaucrat(const std::string _name);
		Bureaucrat(const std::string _name, unsigned int n);
		Bureaucrat(const Bureaucrat& a);
		//Destructor
		virtual ~Bureaucrat();
		//Operator overloaded
		Bureaucrat& operator= (const Bureaucrat& a);
		//Member functions
		const std::string getName() const;
		unsigned int getGrade() const;
		void setGrade(unsigned int n);
		void incrementGrade(unsigned int n);
		void decrementGrade(unsigned int n);
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

class Exception : public std::exception {
	public:
		const char* what() const throw();
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& a);

#endif
