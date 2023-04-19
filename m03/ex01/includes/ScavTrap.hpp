/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/04/19 15:17:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
// Default constructor
	ScavTrap(std::string name);

// Copy constructor
	ScavTrap(const ScavTrap &other);

// Destructor
	~ScavTrap();

// Copy assignment operator
	ScavTrap & operator=(const ScavTrap &other);

	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif /* SCAVTRAP_HPP */
