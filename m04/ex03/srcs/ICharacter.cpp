/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/25 10:58:02 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ICharacter.hpp"

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
