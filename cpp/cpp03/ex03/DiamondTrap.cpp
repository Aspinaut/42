/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:36 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 09:41:17 by vmasse           ###   ########.fr       */
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

DiamondTrap::DiamondTrap(DiamondTrap const &ref) : ClapTrap(ref.getName()), ScavTrap(ref.getName()), FragTrap(ref.getName()), _name(ref.getName())
{
	this->ClapTrap::setName(ref.getName() + "_clap_name");
	this->_hitPts = this->FragTrap::getHitPts();
	this->_energyPts = this->ScavTrap::getEnergyPts();
	this->_attackDmg = this->FragTrap::getAttackDmg();
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
		
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	this->_name = ref.getName();
	this->_hitPts = ref.getHitPts();
	this->_energyPts = ref.getEnergyPts();
	this->_attackDmg = ref.getAttackDmg();
	return *this;
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