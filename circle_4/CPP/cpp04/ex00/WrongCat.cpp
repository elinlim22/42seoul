#include "WrongCat.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
WrongCat::WrongCat() : type("WrongCat") {
	std::cout << "<<< WrongCat Constructor called >>>" << std::endl;
}

WrongCat::WrongCat(const WrongCat& a) {
	std::cout << "<<< WrongCat Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
WrongCat::~WrongCat() {
	std::cout << "<<< WrongCat Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
WrongCat& WrongCat::operator= (const WrongCat& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void WrongCat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}

std::string WrongCat::getType() const {
	return type;
}
