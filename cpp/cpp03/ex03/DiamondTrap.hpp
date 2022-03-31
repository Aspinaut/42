/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:29 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 09:34:15 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
	
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &ref);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &ref);

		std::string getName() const;
		void setName(std::string const &name);

		void whoAmI();
		void attack(std::string const &target);

	private:

		std::string _name;
};

#endif