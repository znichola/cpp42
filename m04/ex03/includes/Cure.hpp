/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:17 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 22:16:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

#include <iostream>

class Cure : public AMateria
{
private:

public:
// Default constructor
	Cure();

// Copy constructor
	Cure(const Cure &other);

// Destructor
	~Cure();

// Copy assignment operator
	Cure & operator=(const Cure &other);

	virtual void		use(ICharacter &target);
	virtual AMateria	*clone() const;
};

#endif /* CURE_HPP */
