#include "ScavTrap.hpp"

int main() {
	ClapTrap* A = new ScavTrap();
	ScavTrap B("Ben");
	// ScavTrap C;
	// ClapTrap D;

	A->actionAttack(B);
	B.beRepaired(10);

	delete A;
	// C = A;
	// std::cout << C.getName() << std::endl;
	// D = C;
	// std::cout << D.getName() << std::endl;
	// std::cout << B.getName() << std::endl;

	// std::cout << A.hit_points << std::endl;
	// std::cout << A.energy_points << std::endl;
	// std::cout << A.attack_damage << std::endl;
	return 0;
}
