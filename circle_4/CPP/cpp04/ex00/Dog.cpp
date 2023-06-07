#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Dog::Dog() : type("Dog") {
	std::cout << "<<< Dog Constructor called >>>" << std::endl;
}

Dog::Dog(const Dog& a) {
	std::cout << "<<< Dog Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Dog::~Dog() {
	std::cout << "<<< Dog Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Dog& Dog::operator= (const Dog& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void Dog::makeSound() const {
	std::cout << "Wof!" << std::endl;
}

std::string Dog::getType() const {
	return type;
}
