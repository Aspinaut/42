/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 14:02:29 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/26 15:32:36 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
	public:

		ScavTrap();
		ScavTrap(const std::string name);
		~ScavTrap();
		void attack(const std::string& target);

};

#endif