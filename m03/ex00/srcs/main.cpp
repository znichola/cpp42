/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:34 by znichola          #+#    #+#             */
/*   Updated: 2023/05/11 10:13:48 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int	main(void)
{

	ClapTrap def;

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

	a = c;
	a.statRep();
	c.statRep();

	std::cout << std::endl;

	return(0);
}
