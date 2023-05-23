/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:18 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
private:

public:
// Default constructor
	ICharacter();

// Copy constructor
	ICharacter(const ICharacter &other);

// Destructor
	~ICharacter();

// Copy assignment operator
	ICharacter & operator=(const ICharacter &other);
};

#endif /* ICHARACTER_HPP */
