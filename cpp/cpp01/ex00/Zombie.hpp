/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:35:04 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/24 11:43:02 by vmasse           ###   ########.fr       */
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

		void announce( void );

	private:

		const std::string _name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
