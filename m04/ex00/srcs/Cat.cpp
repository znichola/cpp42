/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:48:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Default constructor
Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "   Cat: Constructing a " << type << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other)
{
	std::cout << "   Cat: Copy Constructing a " << type << std::endl;
	Animal::operator=(other);
}

// Destructor
Cat::~Cat()
{
	std::cout << "   Cat: Destroying a " << type << std::endl;
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	return *this;
}

// method
void	Cat::makeSound(void) const
{
	std::cout << "Miawww Miaowww" << std::endl;
}