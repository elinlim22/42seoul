#include "Zombie.hpp"

int main() {
	Zombie* list = zombieHorde(5, "baby");
	delete []list;
	return 0;
}
