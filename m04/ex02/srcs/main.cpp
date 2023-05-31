/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 10:21:49 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <assert.h>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define GREEN(w)	"\033[92m" << w << "\033[0m"
#define PUT(w)		std::cout NL << w NL
#define NL			<< std::endl

#define NUM_AANIMALS 12

int	main(void)
{
	std::cout << "Welcome to my AAnimal Kingdom!" NL;
	{
		PUT("Given main") NL;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	{
		PUT("My main") NL;
		AAnimal	*jungle[10];
		for (int i = 0; i < 10; i++)
		{
			std::cout << "AAnimal" GREEN("#" << i) << " spawning" NL;
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

		Dog duplicateDog(*(Dog*)jungle[9]);
		Cat duplicateCat = *(Cat*)jungle[8];

		jungle[9]->think();
		duplicateDog.think();
		jungle[8]->think();
		duplicateCat.think();

		PUT("Asserting ideas are the same");
		for (int i = 0; i < 100; i++)
		{
			assert(jungle[9]->exposeBrain()->getIdea(i) ==
				duplicateDog.exposeBrain()->getIdea(i));
			assert(jungle[8]->exposeBrain()->getIdea(i) ==
				duplicateCat.exposeBrain()->getIdea(i));
		}
		PUT("assertiong passed");

		PUT("Deleting the jungle");
		for (int i = 0; i < 10; i++)
			delete jungle[i];

		PUT("Checking the duplicats still have a brains");

		duplicateDog.think();
		duplicateCat.think();

		std::cout << GREEN("leaving scope") NL;
	}

	{
		PUT("Main that's borken uncomment to see how we can't make AAnimals") NL;
		// const AAnimal a();
		// const Dog d();
	}
	return(0);
}
