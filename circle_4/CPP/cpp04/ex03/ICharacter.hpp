#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

class AMateria;

/* -------------------------------------------------------------------------- */
/*                          Interface class Character                         */
/* -------------------------------------------------------------------------- */
class ICharacter {
	public:
		virtual ~ICharacter();
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
	private:
		AMateria* inventory[4];
		int index; //??
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
		std::string const& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif
