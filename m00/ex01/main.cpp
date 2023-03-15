/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 04:58:14 by znichola          #+#    #+#             */
/*   Updated: 2023/03/15 02:37:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "phonebook.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::string	buff;
	PhoneBook	phonebook;

	// for random name generation
	std::srand(std::time(0));

	std::cout << "Hello PhoneBook!" << std::endl;
	while (1)
	{
		std::cout << "Command: ";
		if (!std::getline(std::cin, buff) || buff == "EXIT")
			break ;
		if (buff == "ADD")
		{
			phonebook.GetNewContact();
		}
		else if (buff == "SEARCH")
		{
			phonebook.DisplayContacts();
			phonebook.GetContactId();
		}
		else
			std::cout << "\"" << buff << "\" : invalid phonebook command" << std::endl;
	}

}
