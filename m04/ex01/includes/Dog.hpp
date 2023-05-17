/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 21:44:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*noggin;

public:
// Default constructor
	Dog();

// Copy constructor
	Dog(const Dog &other);

// Destructor
	~Dog();

// Copy assignment operator
	Dog & operator=(const Dog &other);

// Methods
	void	makeSound(void) const;
	const Brain	*exposeBrain(void) const;
};

#endif /* DOG_HPP */
