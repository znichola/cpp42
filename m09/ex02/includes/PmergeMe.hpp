/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*   Updated: 2023/07/07 11:53:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <cstdlib>

template<typename T>
class PmergeMe
{
private:
	T _elements;

public:
	PmergeMe() {}
	PmergeMe(const PmergeMe &other) : _elements(other._elements) {}

	~PmergeMe() {}
	
	PmergeMe(int ac, char **av)
	{
		for (int i = 0; i < ac; i++)
			_elements.push_back(std::atoi(av[i]));
	}

	PmergeMe(std::string args)
	{
			std::cout << "string input\n";
		int x = 0;
		std::stringstream ss(args);
		while (ss >> x)
		{
			if (!ss.fail())
				_elements.push_back(x);
		}	
	}

	PmergeMe & operator=(const PmergeMe &other) { _elements = other._elements; return *this; }

	void print() const
	{
		std::cout << "printing Pmerge\n";
		for (typename T::const_iterator it = _elements.begin(); it < _elements.end(); it++)
		{
			if (it != _elements.begin())
				std::cout << ", ";
			std::cout << *it;
		}
		std::cout << std::endl;
	}	
};

#endif /* PMERGEME_HPP */
