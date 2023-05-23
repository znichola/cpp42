/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:15 by znichola          #+#    #+#             */
/*   Updated: 2023/05/23 23:57:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
private:

public:
// Default constructor
	AMateria();

// Copy constructor
	AMateria(const AMateria &other);

// Destructor
	~AMateria();

// Copy assignment operator
	AMateria & operator=(const AMateria &other);
};

#endif /* AMATERIA_HPP */
