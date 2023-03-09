/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:41:48 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 13:15:39 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon		_Weapon;
	std::string	_Name;
public:
	HumanA(std::string newName, Weapon newWeapon);
	~HumanA();

	void	attack(void) const;
};

#endif
