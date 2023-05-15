/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:56:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 20:39:21 by znichola         ###   ########.fr       */
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
	std::cout << " Brain: Is generating 100 ideas" << std::endl;
	for (int i = 0; i < 100; i++) {ideas[i] = SSTR(clock());}
}

// Copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << " Brain: Is copying 100 ideas" << std::endl;
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
	std::cout << " Brain: Is copying and assigning 100 ideas" << std::endl;
	for (int i = 0; i < 100; i++) {ideas[i] = other.ideas[i];}
	return *this;
}
