/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 09:57:36 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

Character::Character() : _name("def_char"), _iMask(0){}

Character::Character(const Character &other)
	: _name(other._name), _iMask(other._iMask)
{
	for (int i = 0; i < 4; i++)
		if (_iMask & (1U << i))
			_inventory[i] = other._inventory[i]->clone();
}

Character::Character(const std::string name)
	: _name(name), _iMask(0)
{

}

// Destructor
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_iMask & (1U << i))
			delete _inventory[i];
}

// Copy assignment operator
Character &Character::operator=(const Character &other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
		if (other._iMask & (1U  << 1))
		{
			if (_iMask & (1U << i))
				delete _inventory[i];
			_inventory[i] = other._inventory[i]->clone();
		}
	_iMask = other._iMask;
	return *this;
}

const std::string &Character::getName(void) const
{
	return (_name);
}


void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (!(_iMask & (1U << i)))
		{
			_inventory[i] = m;
			_iMask |= (1U << i);
			return ;
		}
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		return ;
	if (_iMask & (1U << idx))
		_iMask ^= (1U << idx);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 4 || idx < 0)
		return ;
	if (_iMask & (1U << idx))
		_inventory[idx]->use(target);
}
