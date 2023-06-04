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

/* -------------------------------------------------------------------------- */
/*                          Interface Materia Source                          */
/* -------------------------------------------------------------------------- */
MateriaSource::MateriaSource() {
	// std::cout << "<<< MateriaSource Constructor called >>>" << std::endl;
	for (int i = 0; i < 4; i++) {
		list[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& a) {
	// std::cout << "<<< MateriaSource Copy Constructor called >>>" << std::endl;
	*this = a;
}

MateriaSource::~MateriaSource() {
	// std::cout << "<<< MateriaSource Destructor called >>>" << std::endl;
}

MateriaSource& MateriaSource::operator= (const MateriaSource& a) {
	if (this != &a) {
		for (int i = 0; i < 4; i++) {
			delete list[i];
			list[i] = a.list[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* fancyStuff) {
	int i = 0;
	for (; i < 4; i++) {
		if (list[i] == NULL) break ;
	}
	if (i < 4) list[i] = fancyStuff;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	int i = 0;
	for (; i < 4; i++) {
		if (list[i] == NULL || !(list[i]->getType()).compare(type)) break ;
	}
	if (i == 4) return 0;
	return (list[i]->clone());
}
