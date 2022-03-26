/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:17:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 14:26:37 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "Naming ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPts < 1 || this->_hitPts < 1)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack anymore..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPts--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPts < 1)
	{
		std::cout << "ClapTrap " << this->_name << "is already dead..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " just lost " << amount << " hit points!" << std::endl;
	this->_hitPts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPts < 1 || this->_hitPts < 1)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be repaired..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " just won " << amount << " hit points!" << std::endl;
	this->_energyPts--;
	this->_hitPts += amount;
}

const std::string	ClapTrap::getName()
{
	return this->_name;
}

int	ClapTrap::getHitPts()
{
	return this->_hitPts;
}

int	ClapTrap::getEnergyPts()
{
	return this->_energyPts;
}

int	ClapTrap::getAttackDmg()
{
	return this->_attackDmg;
}
