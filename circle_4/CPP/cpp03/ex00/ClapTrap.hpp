#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <limits>

class ClapTrap {
	private:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
	public:
		//Constructors
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& a);
		//Destructor
		~ClapTrap();
		//Operator overloaded
		ClapTrap &operator= (const ClapTrap& a);
		//Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		const std::string getName();
		void action_attack(ClapTrap& target);
		void callStatus(ClapTrap& a);
};

#endif
