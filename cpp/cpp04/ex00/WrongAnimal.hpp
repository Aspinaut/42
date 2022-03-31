/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/03/31 13:55:59 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;


	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &ref);
		~WrongAnimal();

		WrongAnimal &operator=(WrongAnimal const &ref);

		void setType(std::string type);
		std::string getType() const;
		
		void	makeSound() const;

};

#endif