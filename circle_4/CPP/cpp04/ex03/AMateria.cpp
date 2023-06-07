#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                                  AMateria                                  */
/* -------------------------------------------------------------------------- */
AMateria::AMateria() {
	// std::cout << "<<< AMateria Constructor called >>>" << std::endl;
}

AMateria::AMateria(const AMateria& a) {
	// std::cout << "<<< AMateria Copy Constructor called >>>" << std::endl;
	*this = a;
}

AMateria::AMateria(std::string const& type) {
	// std::cout << "<<< AMateria Constructor called >>>" << std::endl;
	this->type = type;
}

AMateria::~AMateria() {
	// std::cout << "<<< AMateria Destructor called >>>" << std::endl;
}

AMateria& AMateria::operator= (const AMateria& a) {
	if (this != &a) {
		type = a.type;
	}
	return *this;
}

std::string const& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " used " << type << std::endl;
}
