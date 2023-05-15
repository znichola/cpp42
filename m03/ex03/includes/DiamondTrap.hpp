/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:25:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 21:31:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;

public:
// Default constructor
	DiamondTrap();
	DiamondTrap(std::string name);

// Copy constructor
	DiamondTrap(const DiamondTrap &other);

// Destructor
	~DiamondTrap();

// Copy assignment operator
	DiamondTrap & operator=(const DiamondTrap &other);

	// using	ScavTrap::attack;
	void	attack(const std::string &target);

	void	WhoAmI(void);
};

#endif /* DIAMONDTRAP_HPP */
