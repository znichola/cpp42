/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:13:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

// Default constructor
Cat::Cat()
{
}

// Copy constructor
Cat::Cat(const Cat &other)
{
	*this = other;
}

// Destructor
Cat::~Cat()
{
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}


