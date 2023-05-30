/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 21:03:35 by znichola         ###   ########.fr       */
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
	for (int i = 0; i < 4; i++) {delete _inventory[i];}
}

// Copy assignment operator
Character &Character::operator=(const Character &other)
{
	_name = other._name;
	_iMask = other._iMask;
	for (int i = 0; i < 4; i++)
		if (_iMask & (1U << i))
			_inventory[i] = other._inventory[i]->clone();
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
			std::cout << _iMask << " equipping " << m->getType() << std::endl;
			_inventory[i] = m->clone();
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
	std::cout << "trying to use " << idx << " "<< _inventory[idx]->getType() << std::endl;
	_inventory[idx]->use(target);
}
