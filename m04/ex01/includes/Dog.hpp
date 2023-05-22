/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/22 10:39:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain	*_brain;

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
	virtual void		makeSound(void) const;
	virtual	void		think(void) const;
	virtual const Brain	*exposeBrain(void) const;
};

#endif /* DOG_HPP */
