/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/31 09:54:52 by znichola         ###   ########.fr       */
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

	{
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
	}

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


	ICharacter *you;
	ICharacter *it;

	you = new Character("you");
	it = new Character("it");

	you->equip(c);
	you->equip(i);
	you->equip(clone);
	you->equip(i);
	you->equip(i);

	you->use(0, *it);
	you->use(1, *it);
	you->use(2, *it);
	you->use(3, *it);
	you->use(4, *it);

	IMateriaSource *fountain = new MateriaSource();

	fountain->learnMateria(c->clone());
	fountain->learnMateria(i->clone());
	fountain->learnMateria(clone->clone());
	fountain->learnMateria(i->clone());
	fountain->learnMateria(i->clone());

	you->unequip(1);
	you->unequip(0);

	cout << "trying to use after unquiping " << endl;

	you->use(0, *it);
	you->use(1, *it);

	cout << "requip and use" << endl;

	you->equip(fountain->createMateria("ice"));

	cout << "useing slot 0" << endl;
	you->use(0, *it);
	cout << "useing slot 1" << endl;
	you->use(1, *it);
	cout << "useing slot 2" << endl;
	you->use(2, *it);

	cout << "requip another" << endl;
	you->equip(fountain->createMateria("cure"));
	cout << "useing slot 1" << endl;
	you->use(1, *it);

	delete fountain;

	delete you;
	delete it;

	// delete i;
	delete c;
	// delete clone;

	cout << "} end my main" << endl;
	return(0);
}
