/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:57 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:44:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

#include <iostream>

// Default constructor
WrongAnimal::WrongAnimal()
{
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
}

// Copy assignment operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

// Methods
void WrongAnimal::makeSound() const
{
	std::cout << "RAAAHHH" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}
