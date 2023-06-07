#include "Ice.hpp"

Ice::Ice() {
	// std::cout << "<<< Ice Constructor called >>>" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& a) {
	// std::cout << "<<< Ice Copy Constructor called >>>" << std::endl;
	*this = a;
}

Ice::~Ice() {
	// std::cout << "<<< Ice Destructor called >>>" << std::endl;
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

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
