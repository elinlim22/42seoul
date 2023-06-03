#include "ICharacter.hpp"

// class Character : public ICharacter {
// 	private:
// 		Materia inventory[4];
// 		int index; //??
// 		std::string name;
// 	public:
// 		//Constructors
// 		Character();
// 		Character(std::string _name);
// 		Character(const Character& a);
// 		//Destructor
// 		virtual ~Character();
// 		//Operation overloaded
// 		Character& operator= (const Character& a);
// 		//Member functions
// 		std::string const& getName() const override;
// 		void equip(AMateria* m) override;
// 		void unequip(int idx) override;
// 		void use(int idx, ICharacter& target) override;
// };

Character::Character() {}

Character::Character(std::string _name) {}

Character::Character(const Character& a) {}

Character::~Character() {}

Character& Character::operator= (const Character& a) {}

std::string const& Character::getName() const {}

void Character::equip(AMateria* m) {}

void Character::unequip(int idx) {}

void Character::use(int idx, ICharacter& target) {}
