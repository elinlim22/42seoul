#include "Zombie.hpp"

int main() {
	//Main : Stack -> destroy at the end
	Zombie mainZ;
	mainZ.announce();
	std::cout << std::endl;

	//newZombie : Heap
	Zombie* newZ = newZombie(std::string("Heap"));
	newZ->announce();
	delete newZ;
	std::cout << std::endl;

	//Random : Stack
	randomChump(std::string("RandStack"));
	std::cout << std::endl;

	return 0;
}
