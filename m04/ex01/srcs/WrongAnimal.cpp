/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:57 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:48:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

#include <iostream>

// Default constructor
WrongAnimal::WrongAnimal() :
	type("WrongAnimal")
{
	std::cout << "WrongAnimal: Constructing an " << getType() << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) :
	type(other.getType())
{
	std::cout << "WrongAnimal: Copy Constructing an " << getType() << std::endl;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destroying the " << getType() << std::endl;
}

// Copy assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal: Copy assigning an " << getType() << std::endl;
	type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WRRRONG" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
