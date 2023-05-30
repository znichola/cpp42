/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/29 19:25:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : ICharacter
{
private:

public:
// Default constructor
	Character();

// Copy constructor
	Character(const Character &other);

// Destructor
	~Character();

// Copy assignment operator
	Character & operator=(const Character &other);

	const std::string &getName(void) const;
	void equip(const AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif /* CHARACTER_HPP */
