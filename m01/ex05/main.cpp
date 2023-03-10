/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:52:13 by znichola          #+#    #+#             */
/*   Updated: 2023/03/10 11:53:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Harl.hpp"

int	main(void)
{
	// for random msg selection
	std::srand(std::time(0));

	Harl		HarlBot;
	std::string	input;

	do
	{
		std::cout << "Enter a level of complaint: " << std::flush;
		std::cin >> input;
		HarlBot.complain(input);
		std::cout << std::endl;
	} while (input != "EXIT" && input.size() != 0 && !std::cin.eof());

	return 0;
}
