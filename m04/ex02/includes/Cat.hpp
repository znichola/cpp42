/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:52:14 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*_brain;

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
	virtual void		makeSound(void) const;
	virtual	void		think(void) const;
	virtual const Brain	*exposeBrain(void) const;
};

#endif /* CAT_HPP */
