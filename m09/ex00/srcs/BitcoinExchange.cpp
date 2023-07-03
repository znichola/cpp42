/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:37 by znichola          #+#    #+#             */
/*   Updated: 2023/07/03 21:12:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <time.h>

#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange()
{
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
}

// Copy assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	// TODO: insert return statement here
	return *this;
}

int BitcoinExchange::readFile(std::ifstream &ifs)
{
	std::string line;
	int ln = 0;
	// check the first line for seperator information
	if(!std::getline(ifs, line)) return 1;
	size_t x = line.find("date");
	if (x == std::string::npos || x != 0) return 2;
	line.erase(0, 4);
	x = line.find("exchange_rate");
	if (x == std::string::npos || x == 0) return 2;
	line.erase(x, 14);
	if (x != line.length()) return 2;

	std::string sep = line;

	std::cout << "sep is: <" << line << ">\n";
	while(getline(ifs, line))
	{
		ln++;
		x = line.find(sep);
		if (x == std::string::npos || x == 0)
		{
			std::cout << ln << " | " << line
			<< "\n-> \33[1;31mError:\33[0m invalid seperator" << std::endl;
			continue;
		}
		line.replace(x, sep.length(), " ");

		std::istringstream ss(line);
		std::string date, dump;
		float value = 0.0f;
		ss >> date >> value;

		if (ss.fail() || (ss >> dump) || value < 0 )
		{
			std::cout << ln << " | " << line
			<< "\n-> \33[1;31mError:\33[0m date / value" << std::endl;
			continue;
		}
		struct tm t = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		char *c = strptime(date.c_str(), "%Y-%m-%d", &t);
		if (c == NULL || *c != '\0')
		{
			std::cout << ln << " | " << line
			<< "\n-> \33[1;31mError:\33[0m invalid date format" << std::endl;
			continue;
		}
	}
	std::cout << "done\n";
	return 0;
}
