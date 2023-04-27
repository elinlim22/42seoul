#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie();
		void set_name(std::string _name);
		void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif
