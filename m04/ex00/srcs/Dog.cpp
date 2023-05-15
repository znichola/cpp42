/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 15:56:04 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

#include <iostream>

// Default constructor
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "   Dog: Constructing a " << type << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other)
{
	std::cout << "   Dog: Copy Constructing a " << type << std::endl;
	Animal::operator=(other);
	// *this = other;
}

// Destructor
Dog::~Dog()
{
	std::cout << "   Dog: Destroying a " << type << std::endl;
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

// method
void	Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}
