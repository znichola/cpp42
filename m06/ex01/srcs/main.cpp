/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:38:01 by znichola          #+#    #+#             */
/*   Updated: 2023/06/11 15:32:30 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::cout << "hello sreializer!" << std::endl;


int *a;
int b;

char *c = (char *) a; // re-interpret cast bit unchanged
char c = (char) b;	//static cast , possinle bit value changes
int const d = (int const) b; //const cast A EVITER VRAIMNENT PAS BIEN

//dynamic cast
class ALL {};
class A: public ALL {};
class B: public ALL {};

A patate;
ALL * all = dynamic_cast <ALL *> (&patate);
ALL * all2 = ALL origin;
B * patate_b;
A * patate_a;

patate_a = dynamic_cast <A *> (all); //ok
patate_b = dynamic_cast <B *> (all); //pas ok return null;

A patate;
ALL & all = dynamic_cast <ALL &> (&patate);
B & patate_b;
A & patate_a;

patate_a = dynamic_cast <A &> (all); //ok
patate_b = dynamic_cast <B &> (all); //pas ok throw() une exception;


	Data d = {42, 13};

	std::cout << d << "\n";

	return 0;
}
