/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niki <niki@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:00 by znichola          #+#    #+#             */
/*   Updated: 2023/05/24 01:06:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

class MateriaSource
{
private:

public:
// Default constructor
	MateriaSource();

// Copy constructor
	MateriaSource(const MateriaSource &other);

// Destructor
	~MateriaSource();

// Copy assignment operator
	MateriaSource & operator=(const MateriaSource &other);
};

#endif /* MATERIASOURCE_HPP */
