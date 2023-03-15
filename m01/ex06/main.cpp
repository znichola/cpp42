/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:52:13 by znichola          #+#    #+#             */
/*   Updated: 2023/03/10 15:49:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}
	// for random msg selection
	std::srand(std::time(0));

	Harl		HarlBot;
	std::string	input = av[1];

	HarlBot.complain(input);

	return 0;
}
