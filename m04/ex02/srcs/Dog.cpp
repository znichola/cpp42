/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:52:52 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

// Default constructor
Dog::Dog() : AAnimal()
{
	type = "Dog";
	std::cout << "   Dog: Constructing a " << type << std::endl;
	_brain = new Brain();
}

// Copy constructor
Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "   Dog: Copy Constructing a " << type << std::endl;
	_brain = new Brain();
	*_brain = *other._brain;
}

// Destructor
Dog::~Dog()
{
	delete _brain;
	std::cout << "   Dog: Destroying a " << type << std::endl;
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	AAnimal::operator=(other);
	std::cout << "   Dog: Copy Assigning a " << type << std::endl;
	*_brain = *other._brain;
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
