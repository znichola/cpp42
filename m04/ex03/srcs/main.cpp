/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 08:12:05 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>

#include "utils.hpp"

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

using std::cout;
using std::endl;

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::cout << "hello rgp!" << std::endl;

	cout << "given main {" << endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	cout << "} end given main" << endl << endl;

	cout << "my main { " << endl;

	AMateria *i = new Ice();
	AMateria *c = new Cure();

	cout << "i:" << i->getType() << endl;
	cout << "c:" << c->getType() << endl;

	AMateria *clone = i->clone();

	cout << "i clone:" << clone->getType() << endl;

	delete clone;

	clone = c->clone();

	cout << "c clone:" << clone->getType() << endl;

	delete i;
	delete c;
	delete clone;

	AMateria::emptyGarbage();

	cout << "} end my main" << endl;
	return(0);
}
