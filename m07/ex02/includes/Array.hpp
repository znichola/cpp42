/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 11:52:30 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
private:
	size_t	_n;
	T		*_arr;

public:
	Array()						: _n(0)			{ _arr = new T[_n]; }
	~Array()									{    delete [] _arr; }
	Array(unsigned int n)		: _n(n)			{ _arr = new T[_n]; }

	Array(const Array &other)	: _n(other._n)
	{
		_arr = new T[_n];
		for (size_t i = 0; i <_n; i++)
			_arr[i] = other._arr[i];
	}

	Array & operator=(const Array &other)
	{
		_n = other._n;
		delete [] _arr; new T[_n];
		for (size_t i = 0; i < _n; i++)
			_arr[i] = other._arr[i];
	}

	T & operator[](size_t i)
	{
		if (i >= _n)
			throw std::exception();
		return _arr[i];
	}

	size_t size() const { return _n; };
};

#endif /* ARRAY_HPP */
