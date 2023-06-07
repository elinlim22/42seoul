#include "AbstAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
AbstAnimal::AbstAnimal() : type("notype") {
	std::cout << "<<< AbstAnimal Constructor called >>>" << std::endl;
}

AbstAnimal::AbstAnimal(const AbstAnimal& a) {
	std::cout << "<<< AbstAnimal Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
AbstAnimal::~AbstAnimal() {
	std::cout << "<<< AbstAnimal Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
AbstAnimal& AbstAnimal::operator= (const AbstAnimal& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
std::string AbstAnimal::getType() const {
	return type;
}
