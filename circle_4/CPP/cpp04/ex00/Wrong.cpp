#include "Wrong.hpp"

/* -------------------------------------------------------------------------- */
/*                                   WrongAnimal                                   */
/* -------------------------------------------------------------------------- */
WrongAnimal::WrongAnimal() : type("notype") {
	std::cout << "<<< WrongAnimal Constructor called >>>" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
	std::cout << "<<< WrongAnimal Copy Constructor called >>>" << std::endl;
	*this = a;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "<<< WrongAnimal Destructor called >>>" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "I AM NOT AN ANIMAL!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

/* -------------------------------------------------------------------------- */
/*                                     WrongDog                                    */
/* -------------------------------------------------------------------------- */
WrongDog::WrongDog() : type("WrongDog") {
	std::cout << "<<< WrongDog Constructor called >>>" << std::endl;
}

WrongDog::WrongDog(const WrongDog& a) {
	std::cout << "<<< WrongDog Copy Constructor called >>>" << std::endl;
	*this = a;
}

WrongDog::~WrongDog() {
	std::cout << "<<< WrongDog Destructor called >>>" << std::endl;
}

WrongDog& WrongDog::operator= (const WrongDog& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

void WrongDog::makeSound() const {
	std::cout << "Wof!" << std::endl;
}

std::string WrongDog::getType() const {
	return type;
}

/* -------------------------------------------------------------------------- */
/*                                     WrongCat                                    */
/* -------------------------------------------------------------------------- */
WrongCat::WrongCat() : type("WrongCat") {
	std::cout << "<<< WrongCat Constructor called >>>" << std::endl;
}

WrongCat::WrongCat(const WrongCat& a) {
	std::cout << "<<< WrongCat Copy Constructor called >>>" << std::endl;
	*this = a;
}

WrongCat::~WrongCat() {
	std::cout << "<<< WrongCat Destructor called >>>" << std::endl;
}

WrongCat& WrongCat::operator= (const WrongCat& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}

std::string WrongCat::getType() const {
	return type;
}
