#include "Cure.hpp"
#include "ICharacter.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Cure::Cure() {
	// std::cout << "<<< Cure Constructor called >>>" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure& a) {
	// std::cout << "<<< Cure Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Cure::~Cure() {
	// std::cout << "<<< Cure Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Cure& Cure::operator= (const Cure& a) {
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
