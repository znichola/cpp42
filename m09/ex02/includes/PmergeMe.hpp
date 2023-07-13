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
# include <algorithm>

template<typename T>
bool sortp(std::pair<typename T::const_iterator, typename T::const_iterator> i,
		std::pair<typename T::const_iterator, typename T::const_iterator> j)
{
	return *i.first > *j.first; 
}

static bool sorti(int a, int b)
{
	return a > b;
}

template<typename T>
class PmergeMe
{
private:
	T _elements;
	struct timeval start, end;

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
		typename T::const_iterator end = _elements.end();
		if (_elements.size() > 11)
			end = _elements.begin() + 10;
		for (typename T::const_iterator it = _elements.begin(); it < end; it++)
		{
			if (it != _elements.begin())
				std::cout << sep;
			std::cout << *it;
		}
		if (_elements.size() > 11 )
			std::cout << " [...]";
		std::cout << std::endl;
	}

	void before() const { std::cout << "Before: "; print(" "); }

	void after()  const { std::cout << "After:  "; print(" "); }

	void timeSort()
	{
		gettimeofday(&start, 0);
		sort();
		gettimeofday(&end, 0);
	}
	
	void timeReport(const std::string &cont)
	{
		std::cout << std::fixed << std::setw(5);
		
		std::cout << "Time to process range of " << _elements.size()
		<< " elements with std::" << cont << " : ";
		std::cout << long((end.tv_sec - start.tv_sec) * 1e6 + end.tv_usec - start.tv_usec) << " us" << std::endl;
	}

	void sort()
	{
		//split into pairs of values for sorting
		typename T::const_iterator end = _elements.end();
		if (_elements.size() % 2)
			end--;
	
		std::vector<std::pair<typename T::const_iterator, typename T::const_iterator> > pairs;
		T ne;

		for (typename T::const_iterator it = _elements.begin(); it < end; it += 2)
		{
			if (*it < it[1])
				pairs.push_back(std::make_pair(it, it + 1));
			else
				pairs.push_back(std::make_pair(it + 1, it));
		}
		std::sort(pairs.begin(), pairs.end(), sortp<T>);
		for (typename std::vector<std::pair<typename T::const_iterator, typename T::const_iterator> >::const_iterator it = pairs.begin(); it < pairs.end(); it ++)
			ne.push_back(*it->first);

		size_t s = ne.size();
		for (size_t i = s; i > 0; i--)
			ne.insert(std::lower_bound(ne.begin(), ne.end() - i, *pairs[s - i].second, sorti), *pairs[s - i].second);
		
		std::reverse(ne.begin(), ne.end());
		if (_elements.size() % 2)
			ne.insert(std::lower_bound(ne.begin(), ne.end(), _elements.back()), _elements.back());
		_elements = ne;
	}
};

#endif /* PMERGEME_HPP */
