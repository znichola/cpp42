/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:44:10 by znichola          #+#    #+#             */
/*   Updated: 2023/03/15 12:42:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::cout << "Random chomps : " << std::endl;
	randomChump("Bobby");
	randomChump("Sarah");
	randomChump("Lucy");

	std::cout << std::endl <<"New zombie : " << std::endl;
	Zombie	*ZedGeorge = newZombie("George");
	Zombie	*ZedMicheal = newZombie("Micheal");
	Zombie	*ZedAnna = newZombie("Anna");

	ZedGeorge->annouce();
	ZedMicheal->annouce();

	delete ZedGeorge;

	ZedAnna->annouce();

	delete ZedMicheal;
	delete ZedAnna;		//comment out one of these to see a real-life memory leak!
	return 0;
}
