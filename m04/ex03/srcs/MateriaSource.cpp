/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:01 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 22:02:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource()
{
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
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
