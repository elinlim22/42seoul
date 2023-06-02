#include "FragTrap.hpp"

int main() {
	ScavTrap Scav_a;
	FragTrap Frag_a;
	FragTrap B("Ben");
	ClapTrap Clap_a;

	Frag_a.action_attack(B);
	B.beRepaired(10);
	B.highFivesGuys();
	Clap_a.callStatus(Clap_a);
	// std::cout << A.getName() << std::endl;
	// std::cout << B.getName() << std::endl;

	// std::cout << A.hit_points << std::endl;
	// std::cout << A.energy_points << std::endl;
	// std::cout << A.attack_damage << std::endl;
	return 0;
}
