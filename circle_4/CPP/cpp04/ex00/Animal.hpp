#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		//Constructors
		Animal();
		Animal(const Animal& a);
		//Destructor
		virtual ~Animal();
		//Operator overloaded
		Animal& operator= (const Animal& a);
		//Member functions
		virtual void makeSound() const;
		virtual std::string getType() const;
};

#endif
