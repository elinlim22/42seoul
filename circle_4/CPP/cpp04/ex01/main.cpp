#include "Polymorphism.hpp"

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




	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	system("leaks Brain");
	return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:40:38 by pohl              #+#    #+#             */
/*   Updated: 2021/10/05 17:55:52 by pohl             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "Brain.hpp"

// #define NUMBER_OF_ANIMALS 8

// int	main( void )
// {
// 	Animal	*animals[NUMBER_OF_ANIMALS];
// 	Brain	*brain;

// 	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
// 	{
// 		if (i < NUMBER_OF_ANIMALS / 2)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 		std::cout << animals[i]->getType() << std::endl;
// 	}

// 	brain = animals[7]->getBrain();
// 	brain->ideas[0] = "I'm hungry";
// 	brain->ideas[1] = "That's a strange idea I'm having";
// 	brain->ideas[2] = "Ball!!!!!";
// 	brain->ideas[3] = "Squirrel!!!!!";
// 	std::cout << animals[7]->getBrain()->ideas[0] << std::endl;

// 	*(animals[5]) = *(animals[7]);
// 	std::cout << animals[5]->getBrain()->ideas[2] << std::endl;

// 	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
// 		delete animals[i];
// }
