/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:37 by znichola          #+#    #+#             */
/*   Updated: 2023/07/03 21:41:09 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <fstream>


class BitcoinExchange
{
private:
	std::multimap<const std::string, float> _mMap;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange &other);

	int readFile_csv(std::ifstream &ifs);
	int readFile_input(std::ifstream &ifs);
	void findBTCvalue(const std::string &date, float quantity);
};

#endif /* BITCOINEXCHANGE_HPP */
