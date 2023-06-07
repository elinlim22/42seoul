#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
	private:
		std::string type;
	public:
		//Constructors
		Dog();
		Dog(const Dog& a);
		//Destructor
		virtual ~Dog();
		//Operator overloaded
		Dog& operator= (const Dog& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

#endif
