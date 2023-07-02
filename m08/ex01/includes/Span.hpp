/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:15:10 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 20:16:32 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
private:
	unsigned int _nMax;
	std::vector<int> _span;

public:
	Span(unsigned int nMax);
	Span(const Span &other);
	~Span();

	Span & operator=(const Span &other);

	const std::vector<int> &getSpan() const;

	void addNumber(int n);

	template<typename T>
	void addRange(T begin, T end)
	{
		std::cout << "distance is: " << std::distance(begin, end) << " vs size: " << static_cast<long int>(_nMax - _span.size()) <<"\n";
		if (std::distance(begin, end) > static_cast<long int>(_nMax - _span.size()))
			throw std::exception();
		std::vector<int>::iterator tmp = _span.end();
		_span.insert(tmp, begin, end);
		std::sort(tmp, _span.end());
		std::inplace_merge(_span.begin(), tmp, _span.end());
	}

	int shortestSpan() const;
	int longestSpan() const;
};

std::ostream &operator<<(std::ostream &os, const Span &sp);

#endif /* SPAN_HPP */
