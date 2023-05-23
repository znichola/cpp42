/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 14:59:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"

// Default constructor
Animal::Animal() :
	type("Animal")
{
	std::cout << "Animal: Constructing an " << type << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) :
	type(other.getType())
{
	std::cout << "Animal: Copy Constructing an " << type << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal: Destroying the " << type << std::endl;
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Copy assigning an " << type << std::endl;
	type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "RAAAHHH" << std::endl;
}

const std::string Animal::getType() const
{
	return type;
}

const Brain	*Animal::exposeBrain(void) const { return NULL;}
void Animal::think(void) const { }
