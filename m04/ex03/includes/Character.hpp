/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:19 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

class Character
{
private:

public:
// Default constructor
	Character();

// Copy constructor
	Character(const Character &other);

// Destructor
	~Character();

// Copy assignment operator
	Character & operator=(const Character &other);
};

#endif /* CHARACTER_HPP */
