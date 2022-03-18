/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:35:04 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/18 15:35:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	public:

		Zombie( void );
		~Zombie( void );

		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
		void announce( void );
	
	private:

		std::string _name;

};

#endif