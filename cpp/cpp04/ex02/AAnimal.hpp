/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/04 16:54:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(AAnimal const &ref);
		virtual ~AAnimal();

		AAnimal &operator=(AAnimal const &ref);

		void setType(std::string type);
		std::string getType() const;
		
		virtual void	makeSound() const = 0;

};

#endif