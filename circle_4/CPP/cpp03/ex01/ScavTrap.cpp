#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructor                                */
/* -------------------------------------------------------------------------- */
ScavTrap::ScavTrap() {
	std::cout << "<<< ScavTrap Constructor called >>>" << std::endl;
	this->name = "Scav";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string _name) {
	std::cout << "<<< ScavTrap Constructor called >>>" << std::endl;
	this->name = _name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& a) {
	std::cout << "<<< ScavTrap Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ScavTrap::~ScavTrap() {
	std::cout << "<<< ScavTrap Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ScavTrap& ScavTrap::operator= (const ScavTrap& a) {
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
void ScavTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void ScavTrap::guardGate() {
	std::cout << this->name << "is in Gate keeper mode." << std::endl;
}
