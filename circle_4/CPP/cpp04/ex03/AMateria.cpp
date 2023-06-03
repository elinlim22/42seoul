#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                                  AMateria                                  */
/* -------------------------------------------------------------------------- */
AMateria::AMateria() : type("Default Materia") {
	std::cout << "<<< AMateria Constructor called >>>" << std::endl;
}

AMateria::AMateria() {
	std::cout << "<<< AMateria Constructor called >>>" << std::endl;
	this->type = "Default Materia";
}

AMateria::AMateria(const AMateria& a) {
	std::cout << "<<< AMateria Copy Constructor called >>>" << std::endl;
	*this = a;
}

AMateria::AMateria(std::string const& type) {
	std::cout << "<<< AMateria Constructor called >>>" << std::endl;
	this->type = type;
}

AMateria::~AMateria() {
	std::cout << "<<< AMateria Destructor called >>>" << std::endl;

}

AMateria& AMateria::operator= (const AMateria& a) {
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

std::string const& AMateria::getType() const {
	return this->type;
}

// AMateria* AMateria::clone() const {}

void AMateria::use(ICharacter& target) {}

/* -------------------------------------------------------------------------- */
/*                          Interface Materia Source                          */
/* -------------------------------------------------------------------------- */
MateriaSource::MateriaSource() : type("Default MateriaSource") {
	std::cout << "<<< MateriaSource Constructor called >>>" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& a) {
	std::cout << "<<< MateriaSource Copy Constructor called >>>" << std::endl;
	*this = a;
}

MateriaSource::~MateriaSource() {
	std::cout << "<<< MateriaSource Destructor called >>>" << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& a) {
	if (this != &a) {
		this->type = a.type;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria*) {

}

AMateria* MateriaSource::createMateria(std::string const& type) {}
