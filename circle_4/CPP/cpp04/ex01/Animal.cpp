#include "Animal.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Animal::Animal() : type("notype") {
	std::cout << "<<< Animal Constructor called >>>" << std::endl;
}

Animal::Animal(const Animal& a) {
	std::cout << "<<< Animal Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Animal::~Animal() {
	std::cout << "<<< Animal Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Animal& Animal::operator= (const Animal& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void Animal::makeSound() const {
	std::cout << "I AM NOT AN ANIMAL!" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
