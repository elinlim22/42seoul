#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string name;
		unsigned int grade;
	public:
		//Constructors
		Bureaucrat();
		//Destructor
		virtual ~Bureaucrat();
		//Operator overloaded
		Bureaucrat &operator= (const Bureaucrat& a);
		Bureaucrat &operator<< (const Bureaucrat& a);
		//Member functions
		const std::string getName() const;
		const unsigned int getGrade() const;
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


/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
const std::string Bureaucrat::getName() const {
	return (this->name);
}

const unsigned int Bureaucrat::getGrade() const {
	return (this->grade);
}

void Bureaucrat::incrementGrade(int n) {

}

void Bureaucrat::decrementGrade(int n) {

}

/* -------------------------------------------------------------------------- */
/*                             Exception functions                            */
/* -------------------------------------------------------------------------- */
void Bureaucrat::GradeTooHighException() {
	// std::cout << "Exception: Grade is too high\n";
}

void Bureaucrat::GradeTooLowException() {
	// std::cout << "Exception: Grade is too low\n";
}












int main(void) {
	Bureaucrat N;

	return 0;
}
