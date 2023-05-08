/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 19:40:09 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

// Default constructor
Cat::Cat() : Animal()
{
	std::cout << "Constructing a Cat" << std::endl;
	type = "Cat";
	sound = "Miawww Miaowww";
}

// Copy constructor
Cat::Cat(const Cat &other)
{
	std::cout << "Copy Constructing a Cat" << std::endl;
	*this = other;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Destroying a Cat" << std::endl;
}

// Copy assignment operator
Cat &Cat::operator=(const Cat &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}
