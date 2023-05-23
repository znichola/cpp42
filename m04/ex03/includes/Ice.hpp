/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:16 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

class Ice
{
private:

public:
// Default constructor
	Ice();

// Copy constructor
	Ice(const Ice &other);

// Destructor
	~Ice();

// Copy assignment operator
	Ice & operator=(const Ice &other);
};

#endif /* ICE_HPP */
