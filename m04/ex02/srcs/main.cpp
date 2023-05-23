/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 16:02:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

	{
		PUT("Main that's borken uncomment to see how we can't make AAnimals") NL;
		// const AAnimal a();
		// const Dog d();

	}
	return(0);
}
