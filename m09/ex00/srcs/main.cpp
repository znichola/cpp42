/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:37 by znichola          #+#    #+#             */
/*   Updated: 2023/07/03 17:02:11 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Give file path as argument" << std::endl;
		return 1;
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "can't read config file: " << av[1] << std::endl;
		return 1;
	}
	BitcoinExchange btc;

	switch (btc.readFile(file))
	{
	case 1:
		std::cerr << "Error with readline" << std::endl;
		break;
	case 2:
		std::cerr << "Header error" << std::endl;
		break;
	default:
		break;
	}


	return 0;
}
