/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 17:22:04 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap clappy("Clappy");
	DiamondTrap diamy("Diamy");
	
	std::cout << diamy.getName() <<  " has : " << diamy.getHitPts() << " hits points." << std::endl;
	std::cout << diamy.getName() <<  " has : " << diamy.getEnergyPts() << " energy points." << std::endl;
	diamy.attack("Clappy");
	clappy.takeDamage(diamy.getAttackDmg());
	std::cout << diamy.getName() <<  " has : " << diamy.getEnergyPts() << " energy points." << std::endl;
	diamy.guardGate();
	diamy.highFivesGuys();
	diamy.whoAmI();
	return 0;
}