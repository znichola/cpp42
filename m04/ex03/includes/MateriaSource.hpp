/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:00 by znichola          #+#    #+#             */
/*   Updated: 2023/05/29 19:22:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
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

	// virtual void		learnMateria(AMateria* mat);
	// virtual AMateria	*createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
