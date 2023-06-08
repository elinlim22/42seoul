// #include "IceCure.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void leaks() {
	system("leaks AMateria");
}

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	me->unequip(3);
	me->unequip(2);
	me->unequip(1);
	// me->unequip(0);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	// leaks();

	atexit(leaks);
	return 0;
}

/*
Should return :

$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$

*/
