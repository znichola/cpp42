/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:25:12 by znichola          #+#    #+#             */
/*   Updated: 2023/05/06 16:25:12 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap
{
private:

public:
// Default constructor
	DiamondTrap();

// Copy constructor
	DiamondTrap(const DiamondTrap &other);

// Destructor
	~DiamondTrap();

// Copy assignment operator
	DiamondTrap & operator=(const DiamondTrap &other);
};

#endif /* DIAMONDTRAP_HPP */
