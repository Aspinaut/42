/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:16:09 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 15:00:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap clappy("Clappy");
	ScavTrap scavy("Scavy");
	

	std::cout << "Clappy has : " << clappy.getEnergyPts() << " energy points." << std::endl;
	std::cout << "Scavy has : " << scavy.getEnergyPts() << " energy points." << std::endl;
	return 0;
}