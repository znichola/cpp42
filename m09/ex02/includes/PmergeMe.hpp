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
		int x = 0;
		std::stringstream ss(args);
		while (ss >> x)
		{
			if (!ss.fail())
				_elements.push_back(x);
		}
	}

	bool is_positive() const
	{
		for (typename T::const_iterator it = _elements.begin(); it < _elements.end(); ++it)
		{
			if (*it < 0)
				return false;
		}
		return true;
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

	bool is_sorted() const { return std::is_sorted(_elements.begin(), _elements.end()); }

	void timeSort()
	{
		T res, seq;
		gettimeofday(&start, 0);
		seq = sort(_elements.begin(), _elements.end());
		for (size_t i = 0; i < seq.size(); ++i)
			res.push_back(_elements[seq[i]]);
		_elements = res;
		gettimeofday(&end, 0);
	}

	void timeReport()
	{
		std::cout << std::fixed << std::setw(5);

		std::cout << "Time to process range of " << _elements.size()
		<< " elements with std::" << _ct << " : ";
		std::cout << long((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec)) << " us" << std::endl;
	}

	void ptr_state(T loc, T seq, std::string msg)
	{
		std::cout << "\n     =>";
		for (size_t i = 0; i < loc.size(); ++i)
			std::cout << " " << loc[i];
		std::cout << "  " << msg << "\n     ->";
			for (size_t i = 0; i < seq.size(); ++i)
				std::cout << " " << B(seq[i]);
		std::cout << "\n";
	}

	void prt_1(T one, std::string msg)
	{
		std::cout << "\n     =>";
		for (size_t i = 0; i < one.size(); ++i)
			std::cout << " " << one[i];
		std::cout << " " << msg << "\n";
	}

	T sort(typename T::iterator begin, typename T::iterator end)
	{
		size_t dist = end - begin;
		size_t mid = dist/2;
		T loc, seq, locL, locR, seqL, seqR, seqRec;
		bool was_odd = false;
		int	locLast, seqLast;

		if (dist % 2) // case when it's odd
		{
			end = end-1;
			locLast = *end;
			seqLast = dist-1;
			dist -= 1;
			was_odd = true;
		}

		if (dist <= 1)
		{
			seqR.push_back(0);
			return seqR;
		}

		for (size_t i = 0; i < dist; ++i)
		{
			loc.push_back(begin[i]);
			seq.push_back(i);
		}

		// ptr_state(loc, seq, "start");
		// make pairs and swap them,
		//  at the same time build up the list of swap instructions
		for (size_t i = 0; i < mid; ++i)
		{
			if (loc[i] > loc[i+mid])
			{
				std::swap(loc[i], loc[i+mid]);
				std::swap(seq[i], seq[i+mid]);
			}
		}
		// std::cout << "\nenter recursion\n";
		// ptr_state(loc, seq, "before rec");
		seqRec = sort(loc.begin() + mid, loc.end());
		// prt_1(seqRec, "re return");
		for (size_t i = 0; i < seqRec.size(); ++i)
		{
			locL.push_back(loc[seqRec[i]]);
			seqL.push_back(seq[seqRec[i]]);
			locR.push_back(loc[seqRec[i]+mid]);
			seqR.push_back(seq[seqRec[i]+mid]);
		}
		// ptr_state(locL, seqL, "shuffy rec L");
		// ptr_state(locR, seqR, "shuffy rec R");

		// std::cout << "     --";
		// now once it's sorted do the binary insertion on pairs
		for (size_t i = 0; i < locL.size(); ++i)
		{
			typename T::iterator ip = std::lower_bound(locR.begin(), locR.begin() + 2 * i, locL[i]);
			int dist = ip - locR.begin();
			locR.insert(ip, locL[i]);
			seqR.insert(seqR.begin() + dist, seqL[i]);
		}
		if (was_odd)
		{
//			std::cout << "last: " << locLast << "\n";
			typename T::iterator ip = std::lower_bound(locR.begin(), locR.end(), locLast);
			int dist = ip - locR.begin();
			locR.insert(ip, locLast);
			seqR.insert(seqR.begin() + dist, seqLast);
		}
		// ptr_state(locR, seqR, "locR endif");
		return seqR;
	}
};

// 6 2 4 5 10 4 4 3 7 6

#endif /* PMERGEME_HPP */
