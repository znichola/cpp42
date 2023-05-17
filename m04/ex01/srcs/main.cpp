/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 22:02:48 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define GREEN(w)	"\033[92m" << w << "\033[0m"
#define PUT(w)		std::cout << w NL;
#define NL			<< std::endl

int	main(void)
{
	std::cout << "Welcome to my Animal Kingdom!" NL;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;

		i = j;

		// assert(j->exposeBrain()->getIdea(1) == i->exposeBrain()->getIdea(1));

		std::cout << std::endl;

		// i->exposeBrain()->printIdeas(10);
		delete j;//should not create a leak
		delete i;
	}
	return(0);
}
