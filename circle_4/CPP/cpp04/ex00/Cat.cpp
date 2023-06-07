#include "Cat.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Cat::Cat() : type("Cat") {
	std::cout << "<<< Cat Constructor called >>>" << std::endl;
}

Cat::Cat(const Cat& a) {
	std::cout << "<<< Cat Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Cat::~Cat() {
	std::cout << "<<< Cat Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Cat& Cat::operator= (const Cat& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void Cat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}

std::string Cat::getType() const {
	return type;
}
