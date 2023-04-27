#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie newZ(name);
	newZ.announce();
}
