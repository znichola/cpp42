/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 21:56:55 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ICharacter.hpp"

#include <iostream>

// Default constructor
ICharacter::ICharacter()
{
	_index = 0;
}

// Copy constructor
ICharacter::ICharacter(const ICharacter &other)
{
	*this = other;
}

// Destructor
ICharacter::~ICharacter() {}

// Copy assignment operator
ICharacter &ICharacter::operator=(const ICharacter &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ICharacter& character)
{
	os << "ICharacter name: " << character.getName();
	return os;
}
