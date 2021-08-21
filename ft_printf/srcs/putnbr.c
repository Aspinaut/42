/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:08:34 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/21 19:16:15 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_unsigned(t_var *vartab, unsigned int n)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr >= 0 && nbr < 10)
		vartab->len_to_print += ft_putchar(nbr + '0');
	else
	{
		ft_putnbr_unsigned(vartab, nbr / 10);
		vartab->len_to_print += ft_putchar(nbr % 10 + '0');
	}
}

void	ft_putnbr(t_var *vartab, int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		vartab->len_to_print += ft_putchar('-');
	}
	if (nbr >= 0 && nbr < 10)
		vartab->len_to_print += ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(vartab, nbr / 10);
		vartab->len_to_print += ft_putchar(nbr % 10 + '0');
	}
}
