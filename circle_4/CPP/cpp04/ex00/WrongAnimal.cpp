#include "WrongAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
WrongAnimal::WrongAnimal() : type("notype") {
	std::cout << "<<< WrongAnimal Constructor called >>>" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
	std::cout << "<<< WrongAnimal Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
WrongAnimal::~WrongAnimal() {
	std::cout << "<<< WrongAnimal Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void WrongAnimal::makeSound() const {
	std::cout << "I AM NOT AN ANIMAL!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
