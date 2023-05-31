/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 14:58:31 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

// Default constructor
Animal::Animal() :
	type("Animal")
{
	std::cout << "Animal: Constructing an " << getType() << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) :
	type(other.getType())
{
	std::cout << "Animal: Copy Constructing an " << getType() << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal: Destroying the " << getType() << std::endl;
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Copy assigning an " << getType() << std::endl;
	type = other.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "RAAAHHH" << std::endl;
}

std::string Animal::getType(void) const
{
	return type;
}
