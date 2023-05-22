/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/22 11:02:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

// Default constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "   Dog: Constructing a " << type << std::endl;
	_brain = new Brain();
	std::cout << " Brain: " << &_brain << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "   Dog: Copy Constructing a " << type << std::endl;
	_brain = new Brain(*other.exposeBrain());
	// _brain = other._brain;
	Animal::operator=(other);
}

// Destructor
Dog::~Dog()
{
	std::cout << "   Dog: Destroying a " << type << std::endl;
	delete _brain;
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "   Dog: Copy Assigning a " << type << std::endl;

	_brain = other._brain;
	Animal::operator=(other);
	return *this;
}

// method
void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

const Brain	*Dog::exposeBrain(void) const
{
	return (_brain);
}

void Dog::think(void) const
{
	std::cout << "   Dog: thought : " << _brain->getIdea(1) << std::endl;
}
