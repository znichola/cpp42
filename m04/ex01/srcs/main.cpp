/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:26:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define GREEN(w)	"\033[92m" << w << "\033[0m"
#define PUT(w)		std::cout NL << w NL
#define NL			<< std::endl

#define NUM_ANIMALS 12

int	main(void)
{
	std::cout << "Welcome to my Animal Kingdom!" NL;
	{
		PUT("Given main") NL;
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	{
		PUT("My main") NL;
		Animal	*jungle[10];
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Animal" GREEN("#" << i) << " spawning" NL;
			if (i % 2)
				jungle[i] = new Dog();
			else
				jungle[i] = new Cat();
			std::cout NL;
		}
		jungle[0]->think();
		jungle[1]->think();
		jungle[2]->think();

		std::cout NL << GREEN("Testing copying") NL;

		Dog duplicatDog(*(Dog*)jungle[9]);

		jungle[9]->think();
		duplicatDog.think();

		PUT("Deleting the jungle");
		for (int i = 0; i < 10; i++)
			delete jungle[i];

		PUT("Checking the duplicat dog still has a brain");

		duplicatDog.think();

		std::cout << GREEN("leaving scope") NL;
	}

	// {
	// 	PUT("My main") NL;

	// 	Animal *jungle[NUM_ANIMALS];
	// 	for (int i = 0; i < NUM_ANIMALS; i++)
	// 	{
	// 		if (i % 2)
	// 			jungle[i] = new Cat();
	// 		else
	// 			jungle[i] = new Dog();
	// 	}
	// 	// assert(j->exposeBrain()->getIdea(1) == i->exposeBrain()->getIdea(1));

	// 	std::cout << std::endl;

	// 	for (int i = 0; i < NUM_ANIMALS; i++)
	// 	{
	// 		std::cout << "      : Animal #" << i << " that's a " << jungle[i]->getType() NL;
	// 		jungle[i]->think();
	// 		// jungle[i]->makeSound();
 	// 		std::cout NL;
	// 		// assert()
	// 	}

	// 	for (int i = 0; i < NUM_ANIMALS; i++)
	// 		delete jungle[i];

	// }
	return(0);
}
