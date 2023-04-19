/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:34 by znichola          #+#    #+#             */
/*   Updated: 2023/04/19 13:30:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{

	ClapTrap a("Alice");
	ClapTrap b("Bobby");
	ClapTrap c("Cindy");
	
	std::cout << std::endl;
	
	a.statRep();
	a.takeDamage(4);
	a.beRepaired(3);
	a.beRepaired(5);
	a.beRepaired(8);
	a.statRep();
	
	std::cout << std::endl;

	b.statRep();
	b.takeDamage(91);
	b.beRepaired(41);
	b.statRep();
	
	std::cout << std::endl;


	c.statRep();
	c.attack("Gregg");
	c.setAttackDmg(4);
	c.attack("Georgina");
	c.attack("Galia");
	c.attack("Gleb");
	c.statRep();

	std::cout << std::endl;

	ScavTrap s("Savyy");
	
	s.statRep();
	s.attack("Billy");
	s.beRepaired(12);
	s.takeDamage(2);
	s.guardGate();
	s.statRep();
	
	std::cout << std::endl;

	ScavTrap z = s;
	z.statRep();	

	std::cout << std::endl;
	
	return(0);
}
