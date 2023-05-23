/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 13:53:39 by znichola         ###   ########.fr       */
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
Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "   Cat: Copy Constructing a " << type << std::endl;
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
