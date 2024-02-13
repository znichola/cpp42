/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:37 by znichola          #+#    #+#             */
/*   Updated: 2023/07/23 15:29:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <time.h>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) :
	_mMap(other._mMap) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	_mMap = other._mMap;
	return *this;
}

int BitcoinExchange::readFile_input(std::ifstream &ifs)
{
	std::string line;
	int ln = 0;

	// check the first line for seperator information
	if(!std::getline(ifs, line)) return 1;

	size_t x = line.find("date");
	if (x == std::string::npos || x != 0) return 2;
	line.erase(0, 4);
	x = line.find("value");
	if (x == std::string::npos || x == 0) return 2;
	line.erase(x, 6);
	if (x != line.length()) return 2;

	std::string sep = line;
	if (sep != " | ") return 2;

	while(getline(ifs, line))
	{
		ln++;
		x = line.find(sep);
		if (x == std::string::npos || x == 0)
		{
			std::cerr << "\33[1;31mError:\33[0m bad input => " << line << std::endl;
			continue;
		}
		line.replace(x, sep.length(), " ");

		std::istringstream ss(line);
		std::string date, dump;
		float value = 0.0f;
		ss >> date >> value;

		if (ss.fail() || (ss >> dump))
		{
			std::cerr << "\33[1;31mError:\33[0m bad input => " << line << std::endl;
			continue;
		}
		struct tm t = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		char *c = strptime(date.c_str(), "%Y-%m-%d", &t);
		char x[11];
		if (c == NULL || *c != '\0' || strftime(x, 11, "%F", &t) != 10 || std::string(x) != date)
		{
			std::cerr << "\33[1;31mError:\33[0m invalid date format." << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "\33[1;31mError:\33[0m not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "\33[1;31mError:\33[0m too large a number." << std::endl;
			continue;
		}
		findBTCvalue(date, value);
	}
	return 0;
}

int BitcoinExchange::readFile_csv(std::ifstream &ifs)
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
		char x[11];
		if (c == NULL || *c != '\0' || strftime(x, 11, "%F", &t) != 10 || std::string(x) != date)
		{
			std::cout << ln << " | " << line
			<< "\n-> \33[1;31mError:\33[0m invalid date format" << std::endl;
			continue;
		}
		_mMap.insert(std::make_pair(date, value));
	}
	return 0;
}

void BitcoinExchange::findBTCvalue(const std::string &date, float quantity)
{

	std::multimap<const std::string, float>::const_iterator it = _mMap.lower_bound(date);
	float value;
	if (it == _mMap.begin())
		value = it->second;
	else
	{
		it--;
		value = it->second;
	}
	// std::cout << "found date: " << it->first << "\n";
	std::cout << date << " => " << quantity << " = " << value * quantity << std::endl;
}
