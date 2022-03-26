/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 18:07:55 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clappy("Clappy");
	ScavTrap scavy("Scavy");
	
	std::cout << scavy.getName() <<  " has : " << scavy.getEnergyPts() << " energy points." << std::endl;
	scavy.attack("Clappy");
	clappy.takeDamage(scavy.getAttackDmg());
	scavy.guardGate();
	return 0;
}