/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 09:33:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/17 14:22:41 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);

	// l'année et le mois ne sont pas corrects
	std::cout << '[' << ltm->tm_year << ltm->tm_mon << ltm->tm_mday
   				<< '_' << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
}

Account::Account( int initial_deposit )
{
	this->_displayTimestamp();
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	this->_accountIndex++;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts( void )
{
	// doit return la longueur du tableau qu'on passe en params à 
	return sizeof(t);
}

int	Account::getTotalAmount( void ) { return Account::_totalAmount; }

int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }

int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
				<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:"
				<< deposit << ";amount:" << this->_amount + deposit << std::endl;
	this->_amount += deposit;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	for (int i=0; i < this->_nbAccounts; i++)
	{
		std::cout << "index:" << i << ";amount:" << this->_amount << ";deposits:"
					<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;	
	}
}