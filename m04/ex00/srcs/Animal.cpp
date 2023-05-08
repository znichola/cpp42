/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:43:44 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

#include <iostream>

// Default constructor
Animal::Animal()
{
	std::cout << "Constructing an Animal" << std::endl;
	type = "Generic Animal";
	sound = "Generic cry";
}

// Copy constructor
Animal::Animal(const Animal &other)
{
	std::cout << "Copy Constructing an Animal" << std::endl;

	*this = other;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Destroying an Animal" << std::endl;
}

// Copy assignment operator
Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Copy assigning an Animal" << std::endl;

	type = other.type;
	sound = other.sound;
	return *this;
}

void Animal::makeSound()
{
	std::cout << sound << std::endl;
}

std::string Animal::getType()
{
	return type;
}
