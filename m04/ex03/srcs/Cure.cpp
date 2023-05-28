/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:17 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 18:45:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

// Default constructor
Cure::Cure()
{
}

// Copy constructor
Cure::Cure(const Cure &other)
{
	*this = other;
}

// Destructor
Cure::~Cure()
{
}

// Copy assignment operator
Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

AMateria	*Cure::clone() const
{
	return new Cure();
}
