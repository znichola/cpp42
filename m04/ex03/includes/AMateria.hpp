/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/29 00:16:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

// # pragma once

# include <string>

class ICharacter;

class AMateria
{
protected:
	/* some values */
	std::string _type;

public:
// Default constructor
	AMateria();
	AMateria(const std::string &type);

// Copy constructor
	AMateria(const AMateria &other);

// Destructor
	virtual ~AMateria();

// Copy assignment operator
	AMateria & operator=(const AMateria &other);

	std::string const	&getType() const; // return materia type

	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
};

#endif /* AMATERIA_HPP */
