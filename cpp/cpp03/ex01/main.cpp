/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 10:12:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clappy("Clappy");
	ScavTrap scavy("Scavy");
	
	std::cout << scavy.getName() <<  " has : " << scavy.getEnergyPts() << " energy points, " << scavy.getHitPts() << " hits points and " << scavy.getAttackDmg() << " attack damage." << std::endl;
	scavy.attack(clappy.getName());
	clappy.takeDamage(scavy.getAttackDmg());
	clappy.attack(scavy.getName());
	scavy.takeDamage(clappy.getAttackDmg());
	scavy.guardGate();
	std::cout << scavy.getName() << " now has " << scavy.getEnergyPts() << " energy points and " << scavy.getHitPts() << " hits points." << std::endl;
	std::cout << clappy.getName() << " now has " << clappy.getEnergyPts() << " energy points and " << clappy.getHitPts() << " hits points." << std::endl;
	scavy.beRepaired(1);
	std::cout << scavy.getName() << " now has " << scavy.getEnergyPts() << " energy points and " << scavy.getHitPts() << " hits points." << std::endl;
	return 0;
}