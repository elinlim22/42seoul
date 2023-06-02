#include "ScavTrap.hpp"

int main() {
	ScavTrap A;
	ScavTrap B("Ben");

	A.action_attack(B);
	B.beRepaired(10);
	// std::cout << A.getName() << std::endl;
	// std::cout << B.getName() << std::endl;

	// std::cout << A.hit_points << std::endl;
	// std::cout << A.energy_points << std::endl;
	// std::cout << A.attack_damage << std::endl;
	return 0;
}
