#include "ClapTrap.hpp"

int main() {
	ClapTrap A("Adam");
	ClapTrap B("Ben");

	A.actionAttack(B);
	B.beRepaired(10);

	return 0;
}
