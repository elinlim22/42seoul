#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                                  AMateria                                  */
/* -------------------------------------------------------------------------- */
AMateria::AMateria() {}

AMateria::AMateria(const AMateria& a) {}

AMateria::AMateria(std::string const& type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator= (const AMateria& a) {}

std::string const& AMateria::getType() const {}

AMateria* AMateria::clone() const {}

void AMateria::use(ICharacter& target) {}

/* -------------------------------------------------------------------------- */
/*                          Interface Materia Source                          */
/* -------------------------------------------------------------------------- */
MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& a) {}

MateriaSource::~MateriaSource() {}

MateriaSource& MateriaSource::operator= (const MateriaSource& a) {}

void MateriaSource::learnMateria(AMateria*) {}

AMateria* MateriaSource::createMateria(std::string const& type) {}
