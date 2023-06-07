#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		//Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal& a);
		//Destructor
		~WrongAnimal();
		//Operator overloaded
		WrongAnimal& operator= (const WrongAnimal& a);
		//Member functions
		void makeSound() const;
		std::string getType() const;
};

#endif
