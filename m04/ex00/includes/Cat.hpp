/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/22 10:13:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
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
	virtual void	makeSound(void) const;
};

#endif /* CAT_HPP */
