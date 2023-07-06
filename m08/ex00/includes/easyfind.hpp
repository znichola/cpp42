/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:30:57 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 14:05:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iterator>

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::const_iterator easyfind(const T c, int i)
{
	typename T::const_iterator it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw std::exception();
	return it;
}

#endif /* EASYFIND_HPP */
