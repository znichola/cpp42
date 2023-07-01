/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:02:01 by znichola          #+#    #+#             */
/*   Updated: 2023/07/01 13:54:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

void plusOne(int &v) { v += 1; }

void rot1(char &c)
{
	if (c >= 'a' && c <= 'z')
		c == 'z' ? c = 'a' : c++;
	else if (c >= 'A' && c <= 'Z')
		c == 'Z' ? c = 'A' : c++;
}

void upper(std::string &s)
{
	for (std::string::iterator it = s.begin(); it < s.end(); it++)
		*it = std::toupper(*it);
}

int	main(void)
{
	std::cout << "hello iter!" << std::endl;

	{
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		iter(arr, 10, plusOne);
		for (int i = 0; i < 10; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	{
		char arr[] = "aAzZoOmMiI";
		iter(arr, 10, rot1);
		for (int i = 0; i < 10; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	{
		std::string arr[] = {"foo", "bar", "bizz", "bang",
							"FiZz", "BUZZ", "?!_aa", "a w t", "o", "P"};
		iter(arr, 10, upper);
		for (int i = 0; i < 10; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	return(0);
}
