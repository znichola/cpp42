/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/28 22:16:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

#include <iostream>

class Ice : public AMateria
{
public:
// Default constructor
	Ice();

// Copy constructor
	Ice(const Ice &other);

// Destructor
	~Ice();

// Copy assignment operator
	Ice & operator=(const Ice &other);

	virtual void		use(ICharacter &target);
	virtual AMateria	*clone() const;

};


#endif /* ICE_HPP */
