/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:44:35 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/20 09:32:01 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool	_signed;
		int const _signGrade;		
		int const _signExec;
	
	public:
		Form(std::string const name, int const sg, int const se);
		Form(Form const &ref);
		~Form();

		Form &operator=(Form const &ref);

		std::string const	getName() const;
		bool	getSigned() const;
		void	beSigned(Bureaucrat const &ref);
		int 	getSignGrade() const;
		int 	getSignExec() const;
		void	ErrorThrower(int sg, int se) const;
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form : grade too low...");
				}	
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form : grade too high...");
				}	
		};
};

std::ostream &operator<<(std::ostream &out, Form const &ref);
