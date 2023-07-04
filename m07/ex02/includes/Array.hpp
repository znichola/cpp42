/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:20:46 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 15:43:21 by znichola         ###   ########.fr       */
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
	Array()               : _n(0)  { _arr = new T[_n]; }
	Array(unsigned int n) : _n(n)  { _arr = new T[_n]; }
	~Array()                       {   delete [] _arr; }

	Array(const Array &other) : _n(other._n)
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

	class IndexOutOfBounds : public std::exception
	{
		public:
			const char *what() const throw()
			{ return "Index is out of bounds"; }
	};

	T & operator[](size_t i)
	{
		if (i >= _n)
			throw Array::IndexOutOfBounds();
		return _arr[i];
	}

	size_t size() const { return _n; };
};

#endif /* ARRAY_HPP */
