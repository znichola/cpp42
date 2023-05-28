/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 22:00:53 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

// Default constructor
Character::Character()
{
}

// Copy constructor
Character::Character(const Character &other) : ICharacter(other)
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
	_name = other._name;
	_index = other._index;
	for (int i = 0; i < 4; i++) {_inventory[i] = other._inventory[i];}
	return *this;
}
