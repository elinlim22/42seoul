#include "FragTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructor                                */
/* -------------------------------------------------------------------------- */
FragTrap::FragTrap() {
	std::cout << "<<< FragTrap Constructor called >>>" << std::endl;
	this->name = "Frag";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string _name) {
	std::cout << "<<< FragTrap Constructor called >>>" << std::endl;
	this->name = _name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& a) {
	std::cout << "<<< FragTrap Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
FragTrap::~FragTrap() {
	std::cout << "<<< FragTrap Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
FragTrap& FragTrap::operator= (const FragTrap& a) {
 	if (this != &a) {
		this->name = a.name;
		this->hit_points = a.hit_points;
		this->energy_points = a.energy_points;
		this->attack_damage = a.attack_damage;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void FragTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void FragTrap::highFivesGuys(void) {
	std::cout << this->name << " requested high fives!" << std::endl;
}
