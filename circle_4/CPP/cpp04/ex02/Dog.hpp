#ifndef DOG_HPP
#define DOG_HPP

#include "AbstAnimal.hpp"
#include "Brain.hpp"

class Dog : public AbstAnimal {
	private:
		std::string type;
		Brain* ideas;
	public:
		//Constructors
		Dog();
		Dog(const Dog& a);
		//Destructor
		~Dog();
		//Operator overloaded
		Dog& operator= (const Dog& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

#endif
