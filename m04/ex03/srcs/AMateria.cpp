/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 18:29:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("FooBar") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type) {}

// Destructor
AMateria::~AMateria() {}

// Copy assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	_type = other._type;
	return *this;
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
	/* do some shit to use ur ability on the target */
}
