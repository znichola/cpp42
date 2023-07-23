/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:37 by znichola          #+#    #+#             */
/*   Updated: 2023/07/23 12:26:04 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "\33[1;31mError:\33[0m Give file path as argument."
			<< std::endl;
		return 1;
	}
	std::ifstream file_csv("data.csv");
	if (!file_csv.is_open())
	{
		std::cerr << "\33[1;31mError:\33[0m can't read csv file."
			<< std::endl;
		return 1;
	}
	std::ifstream file_input(av[1]);
	if (!file_input.is_open())
	{
		std::cerr << "\33[1;31mError:\33[0m can't read input file: "
			<< av[1] << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	switch (btc.readFile_csv(file_csv))
	{
	case 1: std::cerr << "\33[1;31mError:\33[0m csv : with readline" << std::endl; return 1;
	case 2: std::cerr << "\33[1;31mError:\33[0m csv : invalid header" << std::endl; return 1;
	}
	switch (btc.readFile_input(file_input))
	{
	case 1: std::cerr << "\33[1;31mError:\33[0m input: with readline" << std::endl; return 1;
	case 2: std::cerr << "\33[1;31mError:\33[0m input: invalid header" << std::endl; return 1;
	}

	return 0;
}
