/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:31:29 by candriam          #+#    #+#             */
/*   Updated: 2025/03/12 06:19:20 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account ( int initial_deposit ) : _accountIndex(_nbAccounts),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:"
		<< checkAmount() << ";" << "created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:"
		<< checkAmount() << ";" << "closed" << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	currTime = std::time(NULL);
	std::tm	*timeInfo = std::localtime(&currTime);
	std::stringstream timeFormatted;
	timeFormatted << std::setw(4) << std::setfill('0') << (timeInfo->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_mon + 1)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_mday)
		<< "_"
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_hour)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_min)
		<< std::setw(2) << std::setfill('0') << (timeInfo->tm_sec);
	std::cout << "[" << timeFormatted.str() << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:"
		<< checkAmount() << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";"
		<< "amount:" << checkAmount() << ";" << "nb_deposits:"
		<< _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:"
		<< checkAmount() << ";";
	if (checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";" << "amount:"
			<< checkAmount() << ";" << "nb_withdrawals:"
			<< _nbWithdrawals << std::endl;
	}
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:"
		<< checkAmount() << ";" << "deposits:" << _nbDeposits
		<< ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:"
		<< getTotalAmount() << ";" << "deposits:" << getNbDeposits()
		<< ";" << "withdrawals:" << getNbWithdrawals() << std::endl;
}
