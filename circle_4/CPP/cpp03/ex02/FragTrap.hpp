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
		virtual ~FragTrap();
		//Operator overloaded
		FragTrap &operator= (const FragTrap& a);
		//Member functions
		void highFivesGuys(void);
		void attack(const std::string& target);
};

#endif
