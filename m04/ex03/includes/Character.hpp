/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 18:27:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

# include "ICharacter.hpp"

class AMateria;
class IMateriaSource;

class Character : public ICharacter
{
private:
	std::string		_name;
	AMateria		*_inventory[4];
	unsigned int	_iMask;

public:
	Character();
	Character(const std::string name);
	Character(const Character &other);

	~Character();

	Character & operator=(const Character &other);

	const std::string &getName(void) const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};


#endif /* CHARACTER_HPP */
