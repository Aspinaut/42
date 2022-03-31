/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:17:08 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 09:28:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPts(10), _energyPts(10), _attackDmg(0)
{
	std::cout << "Naming ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &ref ) : _name(ref.getName()), _hitPts(ref.getHitPts()), _energyPts(ref.getEnergyPts()), _attackDmg(ref.getAttackDmg())
{
	std::cout << "ClapTrap " << ref.getName() << " copy constructor was called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = ref._name;
	this->_hitPts = ref._hitPts;
	this->_energyPts = ref._energyPts;
	this->_attackDmg = ref._attackDmg;
	return *this;
}

void ClapTrap::setName(std::string name) { this->_name = name; }

void ClapTrap::setHitPts(int hits) { this->_hitPts = hits; }

void ClapTrap::setEnergyPts(int energy) { this->_energyPts = energy; }

void ClapTrap::setAttackDmg(int attack) { this->_attackDmg = attack; }

std::string	ClapTrap::getName() const { return this->_name; }

int	ClapTrap::getHitPts() const { return this->_hitPts; }

int	ClapTrap::getEnergyPts() const { return this->_energyPts; }

int	ClapTrap::getAttackDmg() const { return this->_attackDmg; }

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
	std::cout << "ClapTrap " << this->_name << " lost " << amount << " hit points!" << std::endl;
	this->_hitPts -= amount;
	if (this->_hitPts < 1)
		std::cout << "ClapTrap " << this->_name << " just died..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPts < 1 || this->_hitPts < 1)
	{
		std::cout << "ClapTrap " << this->_name << " cannot be repaired..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " won " << amount << " hit points!" << std::endl;
	this->_energyPts--;
	this->_hitPts += amount;
}
