/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 00:44:10 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 02:01:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	const int	num_zeds = 6;

	std::cout << "Hoard mode : " << std::endl;

	Zombie *Zeds = zombieHorde(num_zeds, "Derk");

	for (int i = 0; i < num_zeds; i++)
		Zeds[i].annouce();
	delete []Zeds;
	return 0;
}
