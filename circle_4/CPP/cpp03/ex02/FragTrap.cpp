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

FragTrap::FragTrap(const FragTrap &a) {
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
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */
void FragTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (hit_points <= 0 || energy_points <= 0) return ;
	std::cout << "FragTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (amount > this->hit_points) amount = hit_points;
	this->hit_points -= amount;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (energy_points <= 0) return ;
	std::cout << "FragTrap " << name << " repaired " << amount << " hit points." << std::endl;
	if (std::numeric_limits<unsigned int>::max() - amount < this->hit_points) amount = std::numeric_limits<unsigned int>::max() - this->hit_points;
	this->hit_points += amount;
	this->energy_points--;
	callStatus(*this);
}

void FragTrap::action_attack(FragTrap& target) {
	this->attack(target.getName());
	target.takeDamage(this->attack_damage);
	callStatus(*this);
	callStatus(target);
}

void FragTrap::callStatus(FragTrap& a) {
	std::cout << "FragTrap " << a.name << "'s info --" << std::endl;
	std::cout << "\thit points : " << a.hit_points << std::endl;
	std::cout << "\tenergy points : " << a.energy_points << std::endl;
	std::cout << "\tattack damage : " << a.attack_damage << std::endl;
}
void FragTrap::highFivesGuys(void) {
	std::cout << this->name << " requested high fives!" << std::endl;
}
// void FragTrap::guardGate() {
// 	std::cout << this->name << "is in Gate keeper mode." << std::endl;
// }

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
FragTrap& FragTrap::operator= (const FragTrap &a) {
	if (this == &a)
		return *this;
	this->name = a.name;
	this->hit_points = a.hit_points;
	this->energy_points = a.energy_points;
	this->attack_damage = a.attack_damage;
	return *this;
}
