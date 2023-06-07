#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		AMateria* inventory[4];
		std::string name;
	public:
		//Constructors
		Character();
		Character(std::string _name);
		Character(const Character& a);
		//Destructor
		virtual ~Character();
		//Operation overloaded
		Character& operator= (const Character& a);
		//Member functions
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
