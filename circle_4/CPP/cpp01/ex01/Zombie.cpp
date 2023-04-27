#include "Zombie.hpp"

Zombie::Zombie() : name("MainStack") {}

Zombie::Zombie(std::string _name) : name(_name) {}

Zombie::~Zombie() {
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::set_name(std::string _name) {
	name = _name;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
