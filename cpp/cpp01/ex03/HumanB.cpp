/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:47:04 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 10:42:50 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB() {}

void	HumanB::attack() const
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " has no weapon..." << std::endl;
	}
	else
	{

		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
