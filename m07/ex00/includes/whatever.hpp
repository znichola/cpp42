/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 12:29:49 by znichola          #+#    #+#             */
/*   Updated: 2023/07/01 12:34:03 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_HPP
# define whatever_HPP

template<typename T>
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
const T & min(const T &a, const T &b)
{
	return a < b ? a : b;
}

template<typename T>
const T & max(const T &a, const T &b)
{
	return a > b ? a : b;
}

#endif /* whatever_HPP */
