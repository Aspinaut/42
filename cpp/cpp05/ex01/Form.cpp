/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:52:05 by vmasse            #+#    #+#             */
/*   Updated: 2022/04/23 13:47:16 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, int const sg, int const se) : _name(name), _signGrade(sg), _signExec(se) { ErrorThrower(sg, se); this->_signed = false; }

Form::Form(Form const &ref) : _name(ref.getName()), _signGrade(ref.getSignGrade()), _signExec(ref.getSignExec()) { this->_signed = ref.getSigned(); }

Form::~Form() {}

Form &Form::operator=(Form const &ref)
{
	this->_signed = ref.getSigned();
	return *this;
}

std::string const Form::getName() const { return this->_name; }

bool	Form::getSigned() const { return this->_signed; }

void	Form::beSigned(Bureaucrat const &ref)
{
	if (this->getSigned())
		throw Form::AlreadySigned();
	if (ref.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	this->_signed = true;
}

int Form::getSignGrade() const { return this->_signGrade; }

int Form::getSignExec() const { return this->_signExec; }

void	Form::ErrorThrower(int sg, int se) const
{
	if (sg > 150 || se > 150)
		throw Form::GradeTooLowException();
	else if (sg < 1 || se < 1)
		throw Form::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &out, Form const &ref)
{
	out << ref.getName() << ", form with signGrade " << ref.getSignGrade() << " and with signExec " << ref.getSignExec() << ". ";
	if (ref.getSigned())
		out << "It is signed.";
	else
		out << "It is not signed.";
	return out;
}
