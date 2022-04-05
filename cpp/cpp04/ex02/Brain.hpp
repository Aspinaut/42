/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:00:15 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/01 10:20:26 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# define MAX 100

class Brain
{
	protected:
		std::string _ideas[MAX];
		unsigned int	_index;

	public:
		Brain();
		Brain(Brain const &ref);
		virtual ~Brain();

		Brain &operator=(Brain const &ref);

		void	setIdea(std::string idea);
		std::string getIdea(unsigned int index) const;
		void	fillIdeas();
};

#endif