/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:17:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 13:47:17 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClavTrap.hpp"

ClavTrap::ClavTrap() : _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClavTrap::ClavTrap(const std::string name) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "Naming constructor called" << std::endl;
}

ClavTrap::~ClavTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClavTrap::attack(const std::string& target)
{
	if (this->_energyPts < 1 || this->_hitPts < 1)
	{
		std::cout << "ClavTrap " << this->_name << " cannot attack anymore..." << std::endl;
		return ;
	}
	std::cout << "ClavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPts--;
}

void ClavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPts < 1)
	{
		std::cout << "ClavTrap " << this->_name << "is already dead..." << std::endl;
		return ;
	}
	std::cout << "ClavTrap " << this->_name << " just lost " << amount << " hit points!" << std::endl;
	this->_hitPts -= amount;
}

void ClavTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPts < 1 || this->_hitPts < 1)
	{
		std::cout << "ClavTrap " << this->_name << " cannot be repaired..." << std::endl;
		return ;
	}
	std::cout << "ClavTrap " << this->_name << " just won " << amount << " hit points!" << std::endl;
	this->_energyPts--;
	this->_hitPts += amount;
}

const std::string	ClavTrap::getName()
{
	return this->_name;
}

int	ClavTrap::getHitPts()
{
	return this->_hitPts;
}

int	ClavTrap::getEnergyPts()
{
	return this->_energyPts;
}

int	ClavTrap::getAttackDmg()
{
	return this->_attackDmg;
}
