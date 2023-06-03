#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		//Constructors
		Brain();
		Brain(const Brain& a);
		//Destructor
		virtual ~Brain();
		//Operator overloaded
		Brain& operator= (const Brain& a);
		//Member functions
		std::string* getBrain();
};

#endif
