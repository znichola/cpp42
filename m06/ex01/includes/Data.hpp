/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:38:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/11 15:07:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <ostream>
// # include <iostream>

struct Data
{
	const int x;
	const int y;
	// Data(int xx, int yy);
};

std::ostream &operator<<(std::ostream &os, const Data &d);

#endif /* DATA_HPP */
