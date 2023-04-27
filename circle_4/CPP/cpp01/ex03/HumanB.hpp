#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon* wp;
		std::string name;
	public:
		HumanB();
		HumanB(std::string _name);
		~HumanB();
		void setWeapon(Weapon& _wp);
		void attack();
};

#endif
