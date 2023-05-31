/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 11:59:11 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

# include "Brain.hpp"


class Animal
{
protected:
	std::string	type;

public:
// Default constructor
	Animal();

// Copy constructor
	Animal(const Animal &other);

// Destructor
	virtual ~Animal();

// Copy assignment operator
	Animal & operator=(const Animal &other);

// Methods
	const std::string	getType(void) const;
	virtual void		makeSound(void) const;
	virtual	void		think(void) const;
	virtual const Brain	*exposeBrain(void) const;
};

#endif /* ANIMAL_HPP */
