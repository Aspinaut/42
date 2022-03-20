/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:32:40 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/20 13:11:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type) : _type(type) {}


Weapon::~Weapon() {}

std::string &Weapon::getType() const
{
	std::string &typeRef = _type;
	return typeRef;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}