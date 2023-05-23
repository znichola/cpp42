/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:56:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:14:31 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <time.h>
#include <iostream>
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

// Default constructor
Brain::Brain()
{
	std::cout << " Brain: Construction .. generating 100 unique ideas" << std::endl;
	for (int i = 0; i < 100; i++) {ideas[i] = "idea_" + SSTR(clock());}
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << " Brain: Copy construction .. deep copying my 100 ideas" << std::endl;
	for (int i = 0; i < 100; i++) {ideas[i] = other.ideas[i];}
}

// Destructor
Brain::~Brain()
{
	std::cout << " Brain: Is self destructing" << std::endl;
}

// Copy assignment operator
Brain &Brain::operator=(const Brain &other)
{
	std::cout << " Brain: Copying Assigning ..  deep copying my 100 ideas" << std::endl;
	for (int i = 0; i < 100; i++) {ideas[i] = other.ideas[i];}
	return *this;
}

// Methods
void	Brain::printIdeas(unsigned int how_many) const
{
	if (how_many > 100)
		how_many = 100;
	for (int i = 0; i < (int)how_many; i++) {std::cout << ideas[i] << std::endl;}
}

const std::string	Brain::getIdea(unsigned int index) const
{
	if (index >= 100)
		index = 99;
	return ideas[index];
}
