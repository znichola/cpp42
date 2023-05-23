/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

// Default constructor
Character::Character()
{
}

// Copy constructor
Character::Character(const Character &other)
{
	*this = other;
}

// Destructor
Character::~Character()
{
}

// Copy assignment operator
Character &Character::operator=(const Character &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


