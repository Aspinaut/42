/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:36 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/30 21:28:34 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "Naming DiamondTrap constructor called" << std::endl;
	this->ClapTrap::setName(name + "_clap_name");
	this->_hitPts = this->FragTrap::getHitPts();
	this->_energyPts = this->ScavTrap::getEnergyPts();
	this->_attackDmg = this->FragTrap::getAttackDmg();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << ", but I am also " << this->ClapTrap::getName() << "." << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

std::string DiamondTrap::getName() const
{
	return this->_name;
}

void DiamondTrap::setName(std::string const &name)
{
	this->_name = name;	
}