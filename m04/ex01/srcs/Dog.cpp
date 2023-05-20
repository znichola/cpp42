/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/20 08:33:26 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

#include <iostream>

// Default constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "   Dog: Constructing a " << type << std::endl;
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
	std::cout << "   Dog: Destroying a " << type << std::endl;
	delete noggin;
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
