#include "ICharacter.hpp"
#include "AMateria.hpp"

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

Character::Character() : name("Defaulty") {
	std::cout << "<<< Character Constructor called >>>" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = nullptr;
	}
}

Character::Character(std::string _name) {
	std::cout << "<<< Character Constructor called >>>" << std::endl;
	this->name = _name;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = nullptr;
	}
}

Character::Character(const Character& a) {
	std::cout << "<<< Character Copy Constructor called >>>" << std::endl;
	*this = a;
}

Character::~Character() {
	std::cout << "<<< Character Destructor called >>>" << std::endl;
	for (int i = 0; i < 4; i++) {
		delete this->inventory[i];
	}
}

Character& Character::operator= (const Character& a) {
	if (this != &a) {
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != nullptr) delete this->inventory[i];
			this->inventory[i] = a.inventory[i];
		}
		this->name = a.name;
	}
	return *this;
}

std::string const& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	int i = 0;
	while (this->inventory[i] != nullptr) i++;
	if (i > 3) return ;
	else {
		this->inventory[i] = m;
	}
}

void Character::unequip(int idx) {
	if ((idx >= 0 && idx < 4) && this->inventory[idx] != nullptr)
		// delete this->inventory[idx]; ?????
		this->inventory[idx] = nullptr;
	else return ;
}

void Character::use(int idx, ICharacter& target) {
	if ((idx >= 0 && idx < 4) && this->inventory[idx] != nullptr) {
		this->inventory[idx]->use(target);
	} else return ;
}
