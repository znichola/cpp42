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
				sort_vector_wrap(_elements.begin(), _elements.end());
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


//	typename T sort_vector2(typename T::iterator begin, typename T::iterator end)
//	{
//		size_t size = end - begin;
//		typename T::iterator last;
//
//		std::cout << size << "\n";
//
//		if (size == 1)
//			return ;
//		if (size == 2)
//		{
//			if (*begin > begin[1])
//				std::iter_swap(begin, begin+1);
//			return ;
//		}
//		std::cout << "size: " << size << "\n";
//		if (size & 1U) // is odd
//		{
//			last = end - 1; // end should point to the value after the last one
//			end = end - 1;  // such what begin - end is the size
//		}
//
//		// make the pairs
//		for (size_t i = 0; i < size; i += 2)
//		{
//			std::cout << " [" << begin[i] << ", " << begin[1 + i] << "]";
//			if (begin[i] < begin[1 + i])
//			{
//				std::iter_swap(begin + i, begin + 1 + i);
//				std::cout << "!";
//			}
//		}
//		std::cout << "\n";
//		after();
//		std::cout << "\n";
//
//		// sort the pairs
//		size = (size-1) / 2;
//		int l = 2;
//		for (size_t s = size; s > 2; s= (s+1) / 2)
//		{
//			std::cout << l << " l\n";
//			for (size_t i = 0; i < s; i += 2)
//			{
//				std::cout << " [" << begin[i] << ", " << begin[2 + i] << "]";
//				if (begin[i] > begin[2 + i])
//				{
//					swap_pairs<T>(2, begin + i, begin + 2 + i);
//					std::cout << "!";
//				}
//			}
//			std::cout << "\n";
//			after();
//			std::cout << "\n";
//			l = l << 1U;;
//		}
//		std::cout << "\n\n";
//	}

	void sort_vector_wrap(typename T::iterator begin, typename T::iterator end)
	{
		std::vector<std::pair<typename T::iterator, int> > pairs;
		int i = 0;
		for (typename T::iterator it = begin; it < end; ++it)
		{
			pairs.push_back(std::make_pair(it, i));
			++i;
		}
		(void)sort_vector(pairs.begin(), pairs.end());

		for (typename std::vector<std::pair<typename T::iterator, int> >::iterator it = pairs.begin(); it < pairs.end(); ++it)
		{
			std::cout << *it->first << " ";
		}
	}

	T sort_vector(typename std::vector<std::pair<typename T::iterator, int> >::iterator begin, typename std::vector<std::pair<typename T::iterator, int> >::iterator end)
//	T sort_vector(typename T::iterator begin, typename T::iterator end)
	{
		size_t dist = end - begin;

		std::vector<std::pair<typename T::iterator, int> > pairs;
		int i = 0;
		for (typename std::vector<std::pair<typename T::iterator, int> >::iterator it = begin; it < end; ++it)
		{
			pairs.push_back(std::make_pair(it->first, i));
			++i;
		}

		if (dist == 2 && begin[0] > begin[1])
				std::iter_swap(begin, begin+1);
		else if (dist != 1 && dist != 2 && dist != 0)
		{
			//T sorted = sort_vector(std::vector<std::pair<typename T::iterator, int> >::iterator begin, std::vector<std::pair<typename T::iterator, int> >::iterator end);
		}


		T ret;
		for (typename std::vector<std::pair<typename T::iterator, int> >::iterator it = pairs.begin(); it < pairs.end(); ++it)
		{
			ret.push_back(it->second);
			std::cout << it->second << " ";
		}
		return ret;
	}
};

#endif /* PMERGEME_HPP */
