/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 11:08:20 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	FragTrap fraggy("Fraggy");
	DiamondTrap diamy("Diamy");
	
	std::cout << diamy.getName() <<  " has : " << diamy.getHitPts() << " hits points." << std::endl;
	std::cout << diamy.getName() <<  " has : " << diamy.getEnergyPts() << " energy points." << std::endl;
	diamy.attack("Fraggy");
	fraggy.takeDamage(diamy.getAttackDmg());
	fraggy.attack("Diamy");
	diamy.takeDamage(fraggy.getAttackDmg());
	std::cout << diamy.getName() <<  " has " << diamy.getHitPts() << " hit points and " << diamy.getEnergyPts() << " energy points." << std::endl;
	diamy.beRepaired(15);
	std::cout << diamy.getName() <<  " has " << diamy.getHitPts() << " hit points and " << diamy.getEnergyPts() << " energy points." << std::endl;
	diamy.guardGate();
	diamy.highFivesGuys();
	diamy.whoAmI();

	DiamondTrap a(diamy);
	a.setName("Bob");
	std::cout << "Here is " << a.getName() << ", the copy of Diamy by copy constructor. He has " << a.getHitPts() << " hit points, " << a.getEnergyPts() << " energy points and " << a.getAttackDmg() << " attack damage." << std::endl;
	
	DiamondTrap b;
	b = diamy;
	b.setName("Bobby");
	std::cout << "Here is " << b.getName() << ", the copy of Bob by assignment. He has " << b.getHitPts() << " hit points, " << b.getEnergyPts() << " energy points and " << b.getAttackDmg() << " attack damage." << std::endl;
	
	return 0;
}
