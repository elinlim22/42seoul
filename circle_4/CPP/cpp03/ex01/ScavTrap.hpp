#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:

	public:
		//Constructors
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& a);
		//Destructor
		virtual ~ScavTrap();
		//Operator overloaded
		ScavTrap &operator= (const ScavTrap& a);
		//Member functions
		void attack(const std::string& target);
		void guardGate();
};

#endif
