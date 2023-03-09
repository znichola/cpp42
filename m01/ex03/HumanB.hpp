/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:02:11 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 13:15:44 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	bool		_Armed;
	Weapon		_Weapon;
	std::string	_Name;
public:
	HumanB(std::string newName);
	~HumanB();

	void	attack(void) const;
	void	setWeapon(Weapon newWeapon);
};

#endif
