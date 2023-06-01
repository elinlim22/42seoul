/*
class ClapTrap {
	private:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &a);
		ClapTrap& operator= (const ClapTrap &a);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
*/

#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Constructor                                */
/* -------------------------------------------------------------------------- */
ClapTrap::ClapTrap(std::string _name) : name(_name), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "Constructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                 Destructor                                 */
/* -------------------------------------------------------------------------- */
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator overloaded                            */
/* -------------------------------------------------------------------------- */
ClapTrap& ClapTrap::operator= (const ClapTrap& a) {
	return ()
}

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */
void ClapTrap::attack(const std::string& target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}

