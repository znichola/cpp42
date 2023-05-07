/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:13:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

// Default constructor
Dog::Dog()
{
}

// Copy constructor
Dog::Dog(const Dog &other)
{
	*this = other;
}

// Destructor
Dog::~Dog()
{
}

// Copy assignment operator
Dog &Dog::operator=(const Dog &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


