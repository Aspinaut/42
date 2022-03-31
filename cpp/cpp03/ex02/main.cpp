/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 10:17:46 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ScavTrap scavy("Scavy");
	FragTrap fraggy("Fraggy");
	
	std::cout << fraggy.getName() <<  " has : " << fraggy.getEnergyPts() << " energy points, " << fraggy.getHitPts() << " hits points and " << fraggy.getAttackDmg() << " attack damage." << std::endl;
	fraggy.attack(scavy.getName());
	scavy.takeDamage(fraggy.getAttackDmg());
	scavy.attack(fraggy.getName());
	fraggy.takeDamage(scavy.getAttackDmg());
	std::cout << "Fraggy has " << fraggy.getHitPts() << " hit points and " << fraggy.getEnergyPts() << " energy points." << std::endl;
	fraggy.beRepaired(5);
	std::cout << "Fraggy has " << fraggy.getHitPts() << " hit points and " << fraggy.getEnergyPts() << " energy points." << std::endl;
	fraggy.highFivesGuys();
	return 0;
}