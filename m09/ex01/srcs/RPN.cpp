/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:30:41 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 23:38:43 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

#include <stack>
#include <sstream>
#include <iostream>

// bullshit for the norm
RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return *this; }

// function to do it
void RPN::solve(const std::string &args)
{
	std::stringstream ss(args);
	std::stack<int> stack;
	char tok;

	while (ss >> tok)
	{
		int n, x, y = 0;
		if (!std::isdigit(tok))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			y = stack.top();
			stack.pop();
			x = stack.top();
			stack.pop();
			if      (tok == '+') n = x + y;
			else if (tok == '-') n = x - y;
			else if (tok == '*') n = x * y;
			else if (tok == '/' && y != 0) n = x / y;
			else
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
		}
		else
			n = tok - '0';
		stack.push(n);
	}
	if (stack.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << stack.top() << std::endl;
}
