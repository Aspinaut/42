/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:51:49 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/11 14:07:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int			_grade;
	
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high...");
				}		
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low...");
				}	
		};
		
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &ref);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &ref);

		std::string	const getName() const;
		void		setGrade(int grade);
		int			getGrade() const;

		void	upGrade();
		void	downGrade();
		void 	ErrorThrower(int grade) const;
		void	signForm(Form &f) const;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &ref);
