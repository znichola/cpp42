/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:02:01 by znichola          #+#    #+#             */
/*   Updated: 2023/07/01 13:34:29 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

#endif /* ITER_HPP */
