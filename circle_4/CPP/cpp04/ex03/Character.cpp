#include "Character.hpp"
#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                                Constructors                                */
/* -------------------------------------------------------------------------- */
Character::Character() : name("Default") {
	// std::cout << "<<< Character Constructor called >>>" << std::endl;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(std::string _name) {
	// std::cout << "<<< Character Constructor called >>>" << std::endl;
	name = _name;
	for (int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character& a) {
	// std::cout << "<<< Character Copy Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
Character::~Character() {
	// std::cout << "<<< Character Destructor called >>>" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete inventory[i];
	}
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
Character& Character::operator= (const Character& a) {
	if (this != &a) {
		for (int i = 0; i < 4; i++) {
			delete inventory[i];
			inventory[i] = a.inventory[i];
		}
		name = a.name;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
std::string const& Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	int i = 0;
	for (; i < 4; i++) {
		if (inventory[i] == NULL) break ;
	}
	if (i < 4) inventory[i] = m;
}

void Character::unequip(int idx) {
	if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
		inventory[idx] = NULL;
	else return ;
}

void Character::use(int idx, ICharacter& target) {
	if ((idx >= 0 && idx < 4) && inventory[idx] != NULL) {
		inventory[idx]->use(target);
	} else return ;
}
