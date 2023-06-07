#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
	// std::cout << "<<< Cure Constructor called >>>" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure& a) {
	// std::cout << "<<< Cure Copy Constructor called >>>" << std::endl;
	*this = a;
}

Cure::~Cure() {
	// std::cout << "<<< Cure Destructor called >>>" << std::endl;
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

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
