/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:49:32 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 19:03:33 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>

#include "Span.hpp"

Span::Span(unsigned int nMax) : _nMax(nMax)            { _span.reserve(_nMax); }

Span::Span(const Span &other) : _nMax(other._nMax), _span(other._span)        {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	_nMax = other._nMax;
	_span = other._span;
	return *this;
}

const std::vector<int> &Span::getSpan() const { return _span; }

void Span::addNumber(int n)
{
	if (_span.size() >= _nMax)
		throw std::exception();
	_span.insert(std::lower_bound(_span.begin(),_span.end(), n), n);
}

int Span::shortestSpan() const
{
	size_t x = 0;
	if ((x = _span.size()) <= 1)
		throw std::exception();
	int y = _span[x - 1] - _span[0];
	for(size_t i = 1; i < x; i++)
	{
		int z = _span[i] - _span[i - 1];
		if (z < y)
			y = z;
		if (z == 0)
			break;
	}
	return y;
}

int Span::longestSpan() const
{
	size_t x = 0;
	if ((x = _span.size()) <= 1)
		throw std::exception();
	return _span[x - 1] - _span[0];
}

std::ostream &operator<<(std::ostream &os, const Span &sp)
{
	std::vector<int> span = sp.getSpan();
	for (std::vector<int>::const_iterator it = span.begin(); it < span.end(); it++)
	{
		if (it == span.begin())
			os << *it;
		else
			os << ", " << *it;
	}
	return os;
}
