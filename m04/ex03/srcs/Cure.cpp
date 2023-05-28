/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:17 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 23:48:37 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
	*this = other;
}

// Destructor
Cure::~Cure() {}

// Copy assignment operator
Cure &Cure::operator=(const Cure &other)
{
	_type = other._type;
	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure();
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* shoots and ice bolt at " << target << " *" << std::endl;
}
