#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	private:

	public:
		//Constructors
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& a);
		//Destructor
		~FragTrap();
		//Operator overloaded
		FragTrap &operator= (const FragTrap& a);
		//Member functions
		void highFivesGuys(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void action_attack(FragTrap& target);
		void callStatus(FragTrap& a);
};

#endif
