/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:42:35 by znichola          #+#    #+#             */
/*   Updated: 2023/03/09 00:03:44 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <sstream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "deposits:" << getNbDeposits() << ";"
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_nbAccounts += 1;
}

Account::~Account(void)
{
	_nbAccounts -= 1;
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

	int	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;
	if (p_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout	<< "index:" << this->_accountIndex << ";"
					<< "p_amount:" << p_amount << ";"
					<< "withdrawal:refused"<< std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

static	std::string	add_leading_zero(int n);

void Account::_displayTimestamp(void)
{
	// std::cout << "[19920104_091532] " << std::flush;

	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	std::cout	<< "["
				<< 1900 + local_time->tm_year
				<< add_leading_zero(1 + local_time->tm_mon)
				<< add_leading_zero(local_time->tm_mday)
				<< "_"
				<< add_leading_zero(1 + local_time->tm_hour)
				<< add_leading_zero(1 + local_time->tm_min)
				<< add_leading_zero(1 + local_time->tm_sec)
				<< "] " << std::flush;
}

static	std::string	add_leading_zero(int n)
{
	std::ostringstream	ostr;
	if (n < 10)
		ostr << 0;
	ostr << n;
	return ostr.str();
}

	// time_t ttime = time(0);
	// tm *local_time = localtime(&ttime);
	// std::cout	<< "["
	// 			<< 1900 + local_time->tm_year;
	// if (1 + local_time->tm_mon < 10)
	// 	std::cout	<< "0";
	// std::cout	<< 1 + local_time->tm_mon
	// 			<< local_time->tm_mday
	// 			<< "_"
	// 			<< 1 + local_time->tm_hour
	// 			<< 1 + local_time->tm_min
	// 			<< 1 + local_time->tm_sec
	// 			<< "] " << std::flush;
