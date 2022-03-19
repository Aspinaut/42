/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:35:04 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/19 17:06:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	public:

		Zombie();
		Zombie( std::string name);
		~Zombie();

		void announce( void ) const;
		void setName(const std::string name);

	private:

		std::string _name;

};
		
Zombie* zombieHorde( int N, std::string name );

#endif