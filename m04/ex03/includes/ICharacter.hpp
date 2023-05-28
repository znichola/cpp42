/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/25 10:57:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class ICharacter
{
protected:
	AMateria		_inventory[4];
	unsigned int	_index;

public:
// Default constructor
	ICharacter();

// Copy constructor
	ICharacter(const ICharacter &other);

// Destructor
	virtual ~ICharacter();

// Copy assignment operator
	ICharacter & operator=(const ICharacter &other);

	virtual	const srd::string &getName(void) const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif /* ICHARACTER_HPP */
