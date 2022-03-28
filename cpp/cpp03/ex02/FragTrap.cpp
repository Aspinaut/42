/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:24:14 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 11:32:17 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->setHitPts(100);
	this->setEnergyPts(100);
	this->setAttackDmg(30);
	this->_name = name;
	std::cout << "Naming FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPts < 1 || this->_hitPts < 1)
	{
		std::cout << "FragTrap " << this->_name << " cannot attack anymore..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDmg << " points of damage!" << std::endl;
	this->_energyPts--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << ": \"Give me five !\"" << std::endl;
}