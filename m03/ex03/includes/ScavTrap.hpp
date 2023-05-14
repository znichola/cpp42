/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 19:18:56 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	static const int	_defaultHP;
	static const int	_defaultEP;
	static const int	_defaultAD;

public:
// Default constructor
	ScavTrap();
	ScavTrap(std::string name);

// Copy constructor
	ScavTrap(const ScavTrap &other);

// Destructor
	~ScavTrap();

// Copy assignment operator
	ScavTrap & operator=(const ScavTrap &other);

	void	attack(const std::string &target);
	void	guardGate(void) const;
};

#endif /* SCAVTRAP_HPP */
