/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:24:14 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 09:31:36 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "Naming FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref) : ClapTrap(ref.getName())
{
	this->setHitPts(100);
	this->setEnergyPts(100);
	this->setAttackDmg(30);
	std::cout << "FragTrap " << ref.getName() << " copy constructor was called." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	this->_name = ref.getName();
	this->_hitPts = ref.getHitPts();
	this->_energyPts = ref.getEnergyPts();
	this->_attackDmg = ref.getAttackDmg();
	return *this;
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
