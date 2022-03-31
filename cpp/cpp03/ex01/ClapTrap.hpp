/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:17:18 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 08:58:53 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	public:

		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &ref);
		~ClapTrap();

		ClapTrap &operator=(const ClapTrap &ref);

		void setName(std::string name);
		void setHitPts(int hits);
		void setEnergyPts(int energy);
		void setAttackDmg(int attack);
		std::string	getName() const;
		unsigned int	getHitPts() const;
		unsigned int	getEnergyPts() const;
		unsigned int	getAttackDmg() const;


		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


	protected:

		std::string _name;
		unsigned int	_hitPts;
		unsigned int	_energyPts;
		unsigned int	_attackDmg;
};

#endif