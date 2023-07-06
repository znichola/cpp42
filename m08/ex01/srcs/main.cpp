/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:15:10 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 20:27:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <set>
#include <list>
#include <deque>

#include "Span.hpp"

static int randomNumber()
{
	clock_t x = std::clock();
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x % (1U << 16);
}

int	main(void)
{
	std::cout << "hello span!" << std::endl;

	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "end given test" << std::endl << std::endl;
	{
		Span s(10);
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		s.addNumber(randomNumber());
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		std::cout << s << "\n";
		try
		{
			s.addNumber(randomNumber());
			std::cout << "managed to over stuff the span!" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "span is full: " << e.what() << std::endl;
		}
	}
	{
		Span s(100000);
		for (int i = 0; i < 100000; i++)
			s.addNumber(randomNumber());

		std::cout << "size: " << s.getSpan().size() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
	}
	{
		std::vector<int> a;
		std::deque<int> b;

		for (int i = 0; i < 100; i++)
			a.push_back(randomNumber());
		for (int i = 0; i < 20; i++)
			b.push_back(randomNumber());

		Span s(110);

		s.addRange(a.begin(), a.end());
		try
		{
			s.addRange(b.begin(), b.end());
			std::cout << "managed to over stuff the span!" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cerr << "span is full: " << e.what() << std::endl;
		}
		std::cout << "size: " << s.getSpan().size() << std::endl;
	}
	std::cout << "end my basic tests" << std::endl << std::endl;
	{
		std::set<int> foo;
		Span s(100000);

		for (int i = 0; i < 100000; i++)
			foo.insert(randomNumber());
		s.addRange(foo.begin(), foo.end());

		std::cout << "size: " << s.getSpan().size() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;

		std::cout << "adding more numbers to the span" << std::endl;

		std::list<int> bar;

		for (int i = 0; i < 5000; i++)
			bar.push_back(i * i ^ 42);
		s.addRange(bar.begin(), bar.end());

		std::cout << "size: " << s.getSpan().size() << std::endl;
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
	}
	return(0);
}
