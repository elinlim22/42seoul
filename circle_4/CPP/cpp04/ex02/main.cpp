#include "Polymorphism.hpp"

int main() {
	AbstAnimal* list[100];
	for (int i = 0; i < 4; i++) {
		for (;i < 2; i++) {
			list[i] = new Dog();
		}
		list[i] = new Cat();
	}

	for (int i = 0; i < 4; i++) {
		delete list[i];
	}


	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	system("leaks Brain");
	return 0;
}
