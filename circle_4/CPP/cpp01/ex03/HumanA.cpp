#include "HumanA.hpp"

HumanA::HumanA() : name("Adam") {}
HumanA::HumanA(std::string _name, Weapon& _wp) : wp(&_wp), name(_name) {}
HumanA::~HumanA() {}

void HumanA::setWeapon(Weapon& _wp) {
	wp = &_wp;
}

void HumanA::attack() {
	if (!wp) std::cout << name << " can't find a weapon. Please create one first." << std::endl;
	else std::cout << name << " attacks with his " << wp->getType() << std::endl;
}
