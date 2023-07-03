/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:37 by znichola          #+#    #+#             */
/*   Updated: 2023/07/03 19:57:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <fstream>

class BitcoinExchange
{
private:
	// std::multimap<std::string, std::float>;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange & operator=(const BitcoinExchange &other);
	int readFile(std::ifstream &ifs);
};

#endif /* BITCOINEXCHANGE_HPP */
