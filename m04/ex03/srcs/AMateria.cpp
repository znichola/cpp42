/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

// Default constructor
AMateria::AMateria()
{
}

// Copy constructor
AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

// Destructor
AMateria::~AMateria()
{
}

// Copy assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


