/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 21:30:41 by znichola          #+#    #+#             */
/*   Updated: 2023/07/04 22:04:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
private:
	RPN();
	RPN(const RPN &other);
	~RPN();

	RPN & operator=(const RPN &other);

public:
	static void solve(const std::string &arg);
};

#endif /* RPN_HPP */
