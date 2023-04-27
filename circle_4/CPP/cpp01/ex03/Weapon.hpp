#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string type;

	public:
		Weapon();
		Weapon(std::string wpName);
		~Weapon();
		const std::string &getType() const;
		void setType(std::string _type);
};

#endif
