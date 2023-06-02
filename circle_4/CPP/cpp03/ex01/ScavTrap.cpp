/*
	OCCF (모듈2부터)
		class A
		{
			A(); -> 기본생성자
			~A(); -> 기본소멸자
			A(const A &a); -> 복사생성자
			A &operator= (const A &a); -> 할당 연산자 오버로딩
		};
*/

#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructor                                */
/* -------------------------------------------------------------------------- */
ScavTrap::ScavTrap() {
	std::cout << "<<< Constructor called >>>" << std::endl;
	this->name = "Somebody";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string _name) {
	std::cout << "<<< Constructor called >>>" << std::endl;
	this->name = _name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &a) {
	std::cout << "<<< Constructor called >>>" << std::endl;
	*this = a;
}


/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ScavTrap::~ScavTrap() {
	std::cout << "<<< Destructor called >>>" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void ScavTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "ScavTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (amount > this->hit_points) amount = hit_points;
	this->hit_points -= amount;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (energy_points <= 0) return ;
	std::cout << "ScavTrap " << name << " repaired " << amount << " hit points." << std::endl;
	if (std::numeric_limits<unsigned int>::max() - amount < this->hit_points) amount = std::numeric_limits<unsigned int>::max() - this->hit_points;
	this->hit_points += amount;
	this->energy_points--;
	callStatus(*this);
}

void ScavTrap::action_attack(ScavTrap& target) {
	this->attack(target.getName());
	target.takeDamage(this->attack_damage);
	callStatus(*this);
	callStatus(target);
}

void ScavTrap::callStatus(ScavTrap& a) {
	std::cout << a.name << "'s info --" << std::endl;
	std::cout << "\thit points : " << a.hit_points << std::endl;
	std::cout << "\tenergy points : " << a.energy_points << std::endl;
	std::cout << "\tattack damage : " << a.attack_damage << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << this->name << "is in Gate keeper mode." << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ScavTrap& ScavTrap::operator= (const ScavTrap &a) {
	if (this == &a)
		return *this;
	this->name = a.name;
	this->hit_points = a.hit_points;
	this->energy_points = a.energy_points;
	this->attack_damage = a.attack_damage;
	return *this;
}
