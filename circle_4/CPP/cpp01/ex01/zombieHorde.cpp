#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* list = new Zombie[N];

	for (int i = 0; i < N; i++) {
		list[i].set_name(name);
		list[i].announce();
	}
	return (list);
}
