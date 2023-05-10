/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:07:45 by znichola          #+#    #+#             */
/*   Updated: 2023/05/07 13:35:40 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

public:
// Default constructor
	FragTrap(std::string name);

// Copy constructor
	FragTrap(const FragTrap &other);

// Destructor
	~FragTrap();

// Copy assignment operator
	FragTrap & operator=(const FragTrap &other);

	void	attack(const std::string &target);
	void	highFivesGuys(void);
};

#endif /* FRAGTRAP_HPP */
