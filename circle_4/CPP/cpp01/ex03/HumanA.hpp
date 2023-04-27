#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon* wp;
		std::string name;
	public:
		HumanA();
		HumanA(std::string _name, Weapon& _wp);
		~HumanA();
		void setWeapon(Weapon& _wp);
		void attack();
};

#endif

