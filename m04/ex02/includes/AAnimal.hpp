/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:13:13 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 15:50:23 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

# include "Brain.hpp"


class AAnimal
{
protected:
	std::string	type;

public:
// Default constructor
	AAnimal();

// Copy constructor
	AAnimal(const AAnimal &other);

// Destructor
	virtual ~AAnimal();

// Copy assignment operator
	virtual AAnimal & operator=(const AAnimal &other);

// Methods
	const std::string	getType(void) const;
	virtual void		makeSound(void) const = 0;
	virtual	void		think(void) const = 0;
	virtual const Brain	*exposeBrain(void) const = 0;
};

#endif /* AANIMAL_HPP */
