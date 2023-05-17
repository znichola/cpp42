/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 21:45:05 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain	*noggin;

public:
// Default constructor
	Cat();

// Copy constructor
	Cat(const Cat &other);

// Destructor
	~Cat();

// Copy assignment operator
	Cat & operator=(const Cat &other);

// Methods
	void	makeSound(void) const;
	const Brain	*exposeBrain(void) const;
};

#endif /* CAT_HPP */
