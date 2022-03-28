/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/28 11:30:30 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	ClapTrap clappy("Clappy");
	FragTrap fraggy("Fraggy");
	
	std::cout << fraggy.getName() <<  " has : " << fraggy.getEnergyPts() << " energy points." << std::endl;
	fraggy.attack("Clappy");
	clappy.takeDamage(fraggy.getAttackDmg());
	fraggy.highFivesGuys();
	return 0;
}