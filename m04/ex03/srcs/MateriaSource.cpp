/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:01 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 08:11:38 by znichola         ###   ########.fr       */
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
MateriaSource::~MateriaSource()
{
	for (unsigned int i = 0; i < _sIndex; i++)
	{
		AMateria::removeMat(_stock[i]);
		// delete _stock[i];
	}
}

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
	{
		std::cout << "already leard your 4 materia" << std::endl;
		return ;
	}
	_stock[_sIndex] = mat;
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
