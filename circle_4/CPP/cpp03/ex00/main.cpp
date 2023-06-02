#include "ClapTrap.hpp"

int main() {
	ClapTrap A("Adam");
	ClapTrap B("Ben");

	A.action_attack(B);
	B.beRepaired(10);

	return 0;
}
