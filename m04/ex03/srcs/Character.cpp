/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/29 19:55:38 by znichola         ###   ########.fr       */
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
	for (int i = 0; i < 4; i++) {delete _inventory[i];}
}

// Copy assignment operator
Character &Character::operator=(const Character &other)
{
	_name = other._name;
	_index = other._index;
	for (int i = 0; i < 4; i++) {_inventory[i] = other._inventory[i];}
	return *this;
}

const std::string &Character::getName(void) const
{
	return (_name);
}


void Character::equip(const AMateria *m)
{
	if (_index < 4 && _index > 0)
		return ;
	_inventory[_index] = m->clone();
	_index ++;
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx > 0)
		return ;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx > 0)
		return ;
	_inventory[idx]->use(target);
}
