/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 21:45:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

#include <iostream>

// Default constructor
Dog::Dog() : Animal()
{
	std::cout << "   Dog: Constructing a " << type << std::endl;
	type = "Dog";
	noggin = new Brain();
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "   Dog: Copy Constructing a " << type << std::endl;
	noggin = other.noggin;
}

// Destructor
Dog::~Dog()
{
	delete noggin;
	std::cout << "   Dog: Destroying a " << type << std::endl;
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "   Dog: Copy Assigning a " << type << std::endl;
	Animal::operator=(other);
	noggin = other.noggin;
	return *this;
}

// method
void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}

const Brain	*Dog::exposeBrain(void) const
{
	return (noggin);
}
