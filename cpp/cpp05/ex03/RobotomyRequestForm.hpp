/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:46:33 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 14:55:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : virtual public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &ref);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &ref);

		std::string getTarget() const;

		void		action() const;
};