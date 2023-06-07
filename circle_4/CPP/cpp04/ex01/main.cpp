#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	Animal* list[100];
	for (int i = 0; i < 4; i++) {
		for (;i < 2; i++) {
			list[i] = new Dog();
		}
		list[i] = new Cat();
	}

	for (int i = 0; i < 4; i++) {
		delete list[i];
	}

	return 0;
}
