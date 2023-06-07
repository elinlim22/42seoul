#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	return 0;
}

// #include "WrongAnimal.hpp"

// int main() {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	const WrongAnimal* j = new WrongDog();
// 	const WrongAnimal* i = new WrongCat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	delete meta;
// 	delete j;
// 	delete i;
// 	return 0;
// }
