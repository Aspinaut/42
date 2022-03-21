/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:29:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 10:39:38 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	public:

		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string const &getType() const;
		void setType(std::string type);

	private:

		std::string _type;
};

#endif