#include "HumanB.hpp"

HumanB::HumanB() : wp(NULL), name("Bunny") {}
HumanB::HumanB(std::string _name) : wp(NULL), name(_name) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& _wp) {
	if (!wp) std::cout << name << " holds a " << _wp.getType() << std::endl;
	wp = &_wp;
}

void HumanB::attack() {
	if (!wp) std::cout << name << " does not have any weapon" << std::endl;
	else std::cout << name << " attacks with his " << wp->getType() << std::endl;
}
