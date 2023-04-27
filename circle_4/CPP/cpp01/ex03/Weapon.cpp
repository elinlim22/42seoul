#include "Weapon.hpp"

Weapon::Weapon() : type("a pan") {}
Weapon::Weapon(std::string _type) : type(_type) {}
Weapon::~Weapon() {}

const std::string &Weapon::getType() const {
	return (type);
}

void Weapon::setType(std::string _type) {
	type = _type;
	std::cout << "Weapon changed : " << type << std::endl;
}

