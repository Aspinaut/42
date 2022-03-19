/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:34:59 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/19 17:11:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	const int size = 10;
	Zombie *horde;

	horde = zombieHorde(size, "Bob");
	for (int i=0; i < size; i++)
		horde[i].announce();
	delete [] horde;
	
	return 0;
}