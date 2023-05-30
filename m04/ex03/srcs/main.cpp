/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 23:57:14 by znichola          #+#    #+#             */
/*   Updated: 2023/05/30 21:04:23 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <cassert>

# include "utils.hpp"

# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"

# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# include "ICharacter.hpp"
# include "Character.hpp"

using std::cout;
using std::endl;

template<typename T>
void testAMateria(std::string type);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::cout << "hello rgp!" << std::endl;

	cout << "given main" << endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// cout << "ice:" << src->createMateria("ice")->getType() << endl
	// 	<< "cure:" << src->createMateria("cure")->getType() << endl;

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");

	cout << "tmp:" << tmp->getType() << endl;

	me->equip(tmp);
	tmp = src->createMateria("cure");

	cout << "tmp2:" << tmp->getType() << endl;

	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	cout << "end given main" << endl;

	// {
	// 	testAMateria<Ice>("ice");
	// 	testAMateria<Cure>("cure");
	// 	cout << "materia unit tests passed " << endl;
	// }

	cout << endl;

	cout << "my main" << endl;

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

	return(0);
}

template<typename T>
void testAMateria(std::string type)
{
	// Test default constructor and getType()
	T materia1;
	assert(materia1.getType() == type);

	// Test constructor and getType()
	T materia2(materia1);
	assert(materia2.getType() == type);

	// Test copy constructor and getType()
	T materia3 = materia2;
	assert(materia3.getType() == type);

	// Test assignment operator and getType()
	T materia4;
	materia4 = materia2;
	assert(materia4.getType() == type);

	// Test clone()
	AMateria* clonedMateria = materia4.clone();

	assert(clonedMateria->getType() == materia4.getType());

	delete clonedMateria;
}
