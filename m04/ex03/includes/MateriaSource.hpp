/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:06:00 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 18:15:16 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_stock[4];
	unsigned int _sIndex;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);

	~MateriaSource();

	MateriaSource & operator=(const MateriaSource &other);

	void		learnMateria(AMateria* mat);
	AMateria	*createMateria(std::string const & type);
};

#endif /* MATERIASOURCE_HPP */
