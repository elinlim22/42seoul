#include "Polymorphism.hpp"

/* -------------------------------------------------------------------------- */
/*                                   Animal                                   */
/* -------------------------------------------------------------------------- */
Animal::Animal() : type("notype") {
	std::cout << "<<< Animal Constructor called >>>" << std::endl;
}

Animal::Animal(const Animal& a) {
	std::cout << "<<< Animal Copy Constructor called >>>" << std::endl;
	*this = a;
}

Animal::~Animal() {
	std::cout << "<<< Animal Destructor called >>>" << std::endl;
}

Animal& Animal::operator= (const Animal& a) {
	if (this != &a)
		type = a.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "I AM NOT AN ANIMAL!" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

/* -------------------------------------------------------------------------- */
/*                                     Dog                                    */
/* -------------------------------------------------------------------------- */
Dog::Dog() : type("Dog") {
	std::cout << "<<< Dog Constructor called >>>" << std::endl;
	this->ideas = new Brain();
}

Dog::Dog(const Dog& a) {
	std::cout << "<<< Dog Copy Constructor called >>>" << std::endl;
	*this = a;
}

Dog::~Dog() {
	std::cout << "<<< Dog Destructor called >>>" << std::endl;
	delete ideas;
}

Dog& Dog::operator= (const Dog& a) {
	if (this != &a) {
		type = a.type;
		delete this->ideas;
		this->ideas = new Brain(*a.ideas);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Wof!" << std::endl;
}

std::string Dog::getType() const {
	return type;
}

/* -------------------------------------------------------------------------- */
/*                                     Cat                                    */
/* -------------------------------------------------------------------------- */
Cat::Cat() : type("Cat") {
	std::cout << "<<< Cat Constructor called >>>" << std::endl;
	this->ideas = new Brain();
}

Cat::Cat(const Cat& a) {
	std::cout << "<<< Cat Copy Constructor called >>>" << std::endl;
	*this = a;
}

Cat::~Cat() {
	std::cout << "<<< Cat Destructor called >>>" << std::endl;
	delete ideas;
}

Cat& Cat::operator= (const Cat& a) {
	if (this != &a) {
		type = a.type;
		delete this->ideas;
		this->ideas = new Brain(*a.ideas);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}

std::string Cat::getType() const {
	return type;
}
