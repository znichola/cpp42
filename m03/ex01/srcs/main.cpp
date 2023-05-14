/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:29:34 by znichola          #+#    #+#             */
/*   Updated: 2023/05/14 21:46:13 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define GREEN(w) "\033[92m" << w << "\033[0m"

int	main(void)
{
	{
		std::cout << std::endl
			<< GREEN(">>> THE OG SCAV TRAP <<<") << std::endl << std::endl;
		ClapTrap d1;

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

		std::cout << std::endl;

		a.statRep();
		c.statRep();

		std::cout << std::endl;
	}

	std::cout  << std::endl
		<< GREEN(">>> THE NEW SCAVTRAP <<<") << std::endl << std::endl;

	ScavTrap d2;

	ScavTrap s("Savyy");

	std::cout << std::endl;

	s.statRep();
	s.attack("Billy");
	s.beRepaired(12);
	s.takeDamage(2);
	s.guardGate();
	s.statRep();

	std::cout << std::endl;

	ScavTrap z;

	std::cout << std::endl;

	z = s;

	std::cout << std::endl;

	s.statRep();
	z.statRep();

	std::cout << std::endl;


	ScavTrap t = s;

	std::cout << std::endl;

	s.takeDamage(15);
	s.statRep();
	t.statRep();

	std::cout << std::endl;

	return(0);
}
