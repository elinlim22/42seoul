#ifndef ABSTANIMAL_HPP
#define ABSTANIMAL_HPP

#include <iostream>

class AbstAnimal {
	protected:
		std::string type;
	public:
		//Constructors
		AbstAnimal();
		AbstAnimal(const AbstAnimal& a);
		//Destructor
		virtual ~AbstAnimal();
		//Operator overloaded
		AbstAnimal& operator= (const AbstAnimal& a);
		//Member functions
		virtual void makeSound() const = 0;
		virtual std::string getType() const;
};

#endif
