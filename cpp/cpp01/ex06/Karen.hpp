/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:51:52 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/21 17:18:53 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>

class Karen
{
	public:

		Karen();
		~Karen();
		void complain( std::string level );
		
	private:

		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
};

#endif