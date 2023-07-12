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
# include <sys/time.h>
# include <iomanip>

template<typename T>
class PmergeMe
{
private:
	T _elements;

public:
	PmergeMe() {}
	PmergeMe(const PmergeMe &other) : _elements(other._elements) {}

	~PmergeMe() {}
	
	void init(int ac, char **av)
	{
		for (int i = 0; i < ac; i++)
			_elements.push_back(std::atoi(av[i]));
	}

	void init(std::string args)
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

	void print(std::string sep) const
	{
		for (typename T::const_iterator it = _elements.begin(); it < _elements.end(); it++)
		{
			if (it != _elements.begin())
				std::cout << sep;
			std::cout << *it;
		}
		std::cout << std::endl;
	}

	void before() const { std::cout << "Before: "; print(" "); }

	void after()  const { std::cout << "After:  "; print(" "); }

	void time(const std::string &cont)
	{
		struct timeval start, end;
		std::cout << std::setprecision(5);
		std::cout << "Time to process range of " << _elements.size()
		<< " elements with std::" << cont << " : ";
		gettimeofday(&start,  0);
		sort();
		gettimeofday(&end, 0);
		std::cout << end.tv_usec - start.tv_usec / 100000.0f << " us" << std::endl;
		std::cout << 0.000001f << " us" << std::endl;

	}
	void sort()
	{
		for (int i = 0; i < 100000; i++)
			;
	}	
};

#endif /* PMERGEME_HPP */
