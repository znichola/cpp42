/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/22 11:35:49 by znichola         ###   ########.fr       */
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
		PUT("HERE");

		Animal *d = new Dog();
		Animal *f = new Dog();
		Animal *g = new Dog();

		PUT("HERE2");

		d->think();
		f->think();
		g->think();

		PUT("HERE2");

		*f = *((Dog*)d);

		d->think();
		f->think();
		g->think();

		PUT("HERE3");

		delete d;
		delete f;
		delete g;
	}
		PUT("HERE4");



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
