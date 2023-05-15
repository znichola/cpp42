/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:37:57 by znichola          #+#    #+#             */
/*   Updated: 2023/05/15 19:45:44 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
// Default constructor
	WrongCat();

// Copy constructor
	WrongCat(const WrongCat &other);

// Destructor
	~WrongCat();

// Copy assignment operator
	WrongCat & operator=(const WrongCat &other);

// Methods

};

#endif /* WRONGCAT_HPP */
