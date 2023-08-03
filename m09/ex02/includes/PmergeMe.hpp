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
# include <variant>

#define B(s) "\033[36m" << s << "\033[0m"

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
static void swap_pairs(int sequence_length, typename T::iterator a, typename T::iterator b)
{
	if (std::distance(a, b) == sequence_length) // Check if the distance between a and b is 2
	{
		for (int i = 0; i < sequence_length; i++) {
			std::iter_swap(a + i, b + i);
		}
	}
}

template<typename T>
static void insert2(T &a, int ia, int va, T &b, int ib, int vb)
{
	a.insert(a.begin() + ia, va);
	b.insert(b.being() + ib, vb);
}


template<typename T>
class PmergeMe
{
private:
	T _elements;
	std::string _ct;
	struct timeval start, end;

public:
	PmergeMe(const std::string &ct) : _ct(ct)
	{
		if (_ct == "vector" || _ct == "deque")
			return ;
		std::cout << _ct << " unsupported type" << std::endl;
		exit(1);
	}

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
		if (0)
			sort_old();
		else
		{
			if (_ct == "vector")
				sort_vector(_elements.begin(), _elements.end());
			else
				sort_deque(_elements.begin(), _elements.end());
		}
		gettimeofday(&end, 0);
	}

	void timeReport()
	{
		std::cout << std::fixed << std::setw(5);

		std::cout << "Time to process range of " << _elements.size()
		<< " elements with std::" << _ct << " : ";
		std::cout << long(end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec) << " us" << std::endl;
	}

	void sort_old()
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

	void sort_deque(typename T::iterator begin, typename T::iterator end)
	{
		(void)begin;
		(void)end;
	}

#include <vector>

	T sort_vector(typename T::iterator begin, typename T::iterator end)
	{
		size_t dist = end - begin;
		size_t mid = dist/2;
		T loc, seq;
		T loc2, seq2;

		for (size_t i = 0; i < dist; ++i)
		{
			loc.push_back(begin[i]);
			seq.push_back(i);
		}

		std::cout << "     ->";
		for (size_t i = 0; i < dist; ++i)
				std::cout << " " << B(seq[i]);

		// make pairs and swap them,
		//  at the same time build up the list of swap instructions
		for (size_t i = 0; i < mid; ++i)
		{
			if (begin[i] < begin[i + mid])
			{
				std::swap(loc[i], loc[i+mid]);
				std::swap(seq[i], seq[i+mid]);
			}
		}


		// std::cout << "\n       ";
		// T right = T(begin + mid, end); // this will be used for the recursive sort
		// for (typename T::iterator it = right.begin(); it < right.end(); ++it)
		// {
		// 	std::cout << " " << *it;
		// }
		std::cout << "\n";
		std::cout << "\n     =>";
		for (size_t i = 0; i < dist; ++i)
			std::cout << " " << loc[i];
		std::cout << "\n     ->";
			for (size_t i = 0; i < dist; ++i)
				std::cout << " " << B(seq[i]);

		// prep the new half vectors to insert into
		for (size_t i = 0; i < mid; ++i)
		{
			loc2.insert(loc2.begin() + i, loc[i]);
			seq2.insert(seq2.begin() + i, seq[i]);
		}

		// now once it's sorted do the binary insection on pairs
		for (size_t i = 0; i < mid; ++i)
		{

			int loc_n = loc[seq[i]];
			// insertion point
			typename T::iterator ip = std::lower_bound(loc.begin(), loc.begin() + seq[i], n);
			size_t li = ip - loc.begin();

			loc.erase(loc.begin() + seq[i]);
			loc.insert(loc.begin() + li, loc_n);

			int x = seq[seq[i]];
			// n = seq[i];
			seq.erase(seq.begin() + i);
			seq.insert(seq.begin() + li, x);


			std::cout << "\n  " << n << "  --";
			for (size_t i = 0; i < dist; ++i)
				std::cout << " " << loc[i];
			std::cout << "  li: " << li << "";
			std::cout << "\n     ->";
			for (size_t i = 0; i < dist; ++i)
				std::cout << " " << B(seq[i]);
		}

		std::cout << "\n     =>";
		for (size_t i = 0; i < dist; ++i)
			std::cout << " " << loc[i];

		std::cout << "\n     ->";
		for (size_t i = 0; i < dist; ++i)
			std::cout << " " << B(seq[i]);

		std::cout << "\n";
		std::cout << "\n";
		return seq;
	}


};

#endif /* PMERGEME_HPP */
