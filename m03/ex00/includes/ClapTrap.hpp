/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:34 by znichola          #+#    #+#             */
/*   Updated: 2023/04/14 13:03:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string	_name;
	int		_hitPoints;
	int		_energyPoints;
	int		_attackDamage;	

	static int	_allClaps;
public:
// Default constructor
	ClapTrap(std::string name);

// Copy constructor
	ClapTrap(const ClapTrap &other);

// Destructor
	~ClapTrap();

// Copy assignment operator
	ClapTrap & operator=(const ClapTrap &other);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	statRep(void);
	void	setAttackDmg(unsigned int amount);
	ClapTrap &findClap(std::string name);
};

#endif /* CLAPTRAP_HPP */
