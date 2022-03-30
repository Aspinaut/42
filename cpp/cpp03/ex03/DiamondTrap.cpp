/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:36 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/30 09:41:44 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	std::cout << "Naming DiamondTrap constructor called" << std::endl;
	// ClapTrap::getName();
	_hitPts = FragTrap::getHitPts();
	_energyPts = ScavTrap::getEnergyPts();
	_attackDmg = FragTrap::getAttackDmg();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << " , but I am also " << this->getName() << " ." << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{

}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

void DiamondTrap::setName(std::string const &name)
{
	
}