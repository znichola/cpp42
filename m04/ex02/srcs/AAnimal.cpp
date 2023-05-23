/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:49:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() :
	type("AAnimal")
{
	std::cout << "AAnimal: Constructing an " << type << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal &other) :
	type(other.getType())
{
	std::cout << "AAnimal: Copy Constructing an " << type << std::endl;
}

// Destructor
AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destroying the " << type << std::endl;
}

// Copy assignment operator
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal: Copy assigning an " << type << std::endl;
	type = other.type;
	return *this;
}

const std::string AAnimal::getType() const
{
	return type;
}
