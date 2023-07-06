/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:50:20 by znichola          #+#    #+#             */
/*   Updated: 2023/07/02 22:01:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	MutantStack() {};
	MutantStack(const MutantStack &other)                     { *this = other; }
	~MutantStack() {};
	MutantStack & operator=(const MutantStack &other)
	                          {std::stack<T>::operator=(other) ; return *this; }

	iterator begin()                        { return std::stack<T>::c.begin(); }
	iterator end()                          { return std::stack<T>::c.end();   }
};

#endif /* MUTANTSTACK_HPP */
