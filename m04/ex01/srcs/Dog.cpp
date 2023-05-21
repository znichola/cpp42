/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/20 09:33:01 by znichola         ###   ########.fr       */
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
