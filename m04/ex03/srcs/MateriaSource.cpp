/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:01 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 01:06:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource()
{
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

// Destructor
MateriaSource::~MateriaSource()
{
}

// Copy assignment operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


