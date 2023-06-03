#include "IceCure.hpp"

/* -------------------------------------------------------------------------- */
/*                                     Ice                                    */
/* -------------------------------------------------------------------------- */
Ice::Ice() {
	std::cout << "<<< Ice Constructor called >>>" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& a) {
	std::cout << "<<< Ice Copy Constructor called >>>" << std::endl;
	*this = a;
}

Ice::~Ice() {
	std::cout << "<<< Ice Destructor called >>>" << std::endl;
}

Ice& Ice::operator= (const Ice& a) {
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

/* -------------------------------------------------------------------------- */
/*                                    Cure                                    */
/* -------------------------------------------------------------------------- */
Cure::Cure() {
	std::cout << "<<< Ice Constructor called >>>" << std::endl;

}

Cure::Cure(const Cure& a) {
	std::cout << "<<< Ice Copy Constructor called >>>" << std::endl;
	*this = a;
}

Cure::~Cure() {
	std::cout << "<<< Ice Destructor called >>>" << std::endl;

}

Cure& Cure::operator= (const Cure& a) {
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}
