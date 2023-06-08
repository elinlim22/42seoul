#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructor                                */
/* -------------------------------------------------------------------------- */
ClapTrap::ClapTrap() : name("Clap"), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "<<< ClapTrap Constructor called >>>" << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "<<< ClapTrap Constructor called >>>" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& a) {
	std::cout << "<<< ClapTrap Constructor called >>>" << std::endl;
	*this = a;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ClapTrap::~ClapTrap() {
	std::cout << "<<< ClapTrap Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ClapTrap& ClapTrap::operator= (const ClapTrap& a) {
 	if (this != &a) {
		name = a.name;
		hit_points = a.hit_points; //health of the ClapTrap
		energy_points = a.energy_points;
		attack_damage = a.attack_damage;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */
void ClapTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	// std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (amount > this->hit_points) amount = hit_points;
	this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy_points <= 0) return ;
	// std::cout << "ClapTrap " << name << " repaired " << amount << " hit points." << std::endl;
	if (std::numeric_limits<unsigned int>::max() - amount < this->hit_points) amount = std::numeric_limits<unsigned int>::max() - this->hit_points;
	this->hit_points += amount;
	this->energy_points--;
	// callStatus(*this);
}

const std::string ClapTrap::getName() const {
	return (this->name);
}

void ClapTrap::action_attack(ClapTrap& target) {
	this->attack(target.getName());
	target.takeDamage(this->attack_damage);
	// callStatus(*this);
	// callStatus(target);
}

void ClapTrap::callStatus(ClapTrap& a) {
	std::cout << a.name << "'s info --" << std::endl;
	std::cout << "\thit points : " << a.hit_points << std::endl;
	std::cout << "\tenergy points : " << a.energy_points << std::endl;
	std::cout << "\tattack damage : " << a.attack_damage << std::endl;
}
