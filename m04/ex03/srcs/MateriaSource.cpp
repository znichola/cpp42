/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:01 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 20:37:08 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

#include <iostream>

// Default constructor
MateriaSource::MateriaSource() : _sIndex(0) {}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) : _sIndex(0)
{
	*this = other;
}

// Destructor
MateriaSource::~MateriaSource() {}

// Copy assignment operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	if (_sIndex >= 4)
		_sIndex = 0;
	delete _stock[_sIndex];
	_stock[_sIndex] = mat->clone();
	std::cout << "learned " << _stock[_sIndex]->getType() << std::endl;
	_sIndex += 1;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (unsigned i = 0; i < _sIndex; i++)
	{
		if (_stock[i]->getType() == type)
			return _stock[i]->clone();
	}
	return 0;
}
