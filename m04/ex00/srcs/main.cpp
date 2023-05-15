/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:39:12 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define GREEN(w)	"\033[92m" << w << "\033[0m"
#define PUT(w)		std::cout << w NL;
#define NL			<< std::endl
int	main(void)
{
	std::cout << "Welcome to my Animal Kingdom!" NL;
	std::cout NL;
	std::cout << "Given main" NL NL;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout NL << "And cleanup to plug the leaks!" NL NL;
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout NL << "My main" NL NL;
		{
			const Animal *pa = new Animal();
			std::cout	<< GREEN("pa ") << pa->getType() << " says ";
			pa->makeSound();
			std::cout NL;

			const Animal f = *pa;

			std::cout	<< GREEN("f  ")
			<< pa->getType() << " says ";
			pa->makeSound();

			delete pa;
		}
		std::cout NL << " -- " NL;
		{
			std::cout NL;
			const Animal *d = new Dog();
			std::cout	<< GREEN("pa ") << d->getType() << " says ";
			d->makeSound();
			std::cout NL;

			const Animal *f = d;

			std::cout	<< GREEN("f  ")
			<< f->getType() << " says ";
			f->makeSound();
			std::cout NL;

			delete d;
		}
		std::cout NL << " -- " NL;
		{
			std::cout NL;
			const Animal *d = new Dog();
			std::cout	<< GREEN("pa ") << d->getType() << " says ";
			d->makeSound();
			std::cout NL;

			const Animal f(*d);

			std::cout	<< GREEN("f  ") << f.getType() << " says ";
			f.makeSound();
			/*
				f is declared as an animal and not a pointer to, so it wont
				inherit the type of a child used to construct it, like the
				next example. I think?
			*/
			std::cout NL;

			delete d;
		}
		std::cout NL << " -- " NL;
		{
			std::cout NL;
			const Animal *d = new Dog();
			std::cout	<< GREEN("pa ") << d->getType() << " says ";
			d->makeSound();
			std::cout NL;

			const Animal *f(d);

			std::cout	<< GREEN("f  ") << f->getType() << " says ";
			f->makeSound();
			/*
				*f is a pointer so it the object pointed too can be a class
				that inherits animal! hence the woof woof.
			*/
			std::cout NL;

			delete d;
		}
	}
	{
		std::cout NL << "Wrong Animal!!" NL NL;
	}

	return(0);
}
