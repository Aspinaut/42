/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:36 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 09:13:07 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHitPts(100);
	this->setEnergyPts(50);
	this->setAttackDmg(20);
	std::cout << "Naming ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &ref ) : ClapTrap(ref.getName())
{
	this->setHitPts(100);
	this->setEnergyPts(50);
	this->setAttackDmg(20);
	std::cout << "ScavTrap " << ref.getName() << " copy constructor was called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->_name = ref.getName();
	this->_hitPts = ref.getHitPts();
	this->_energyPts = ref.getEnergyPts();
	this->_attackDmg = ref.getAttackDmg();
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPts() < 1 || this->getHitPts() < 1)
	{
		std::cout << "ScavTrap " << this->getName() << " cannot attack anymore..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDmg() << " points of damage!" << std::endl;
	this->setEnergyPts(this->getEnergyPts() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now entering in gate keeper mode !" << std::endl; 
}
