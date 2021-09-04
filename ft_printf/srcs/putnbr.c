/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:08:34 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/04 09:15:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_unsigned(t_var *vartab, unsigned int n)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr < 10)
		vartab->len += ft_putchar(nbr + '0');
	else
	{
		ft_putnbr_unsigned(vartab, nbr / 10);
		vartab->len += ft_putchar(nbr % 10 + '0');
	}
}

void	ft_putnbr(t_var *vartab, int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		vartab->len += ft_putchar('-');
	}
	if (nbr >= 0 && nbr < 10)
		vartab->len += ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(vartab, nbr / 10);
		vartab->len += ft_putchar(nbr % 10 + '0');
	}
}

void ft_putnbr_hex(t_var *vartab, unsigned int nb, unsigned int converter)
{
	unsigned int	remainder;
	unsigned int	nb_cpy;

	remainder = 0;
	nb_cpy = nb;
	if (nb > 15)
	{
		nb = nb / 16;
		remainder = nb_cpy - (nb * 16);
		if (remainder < 10)
		{
			ft_putnbr_hex(vartab, nb, converter);
			vartab->len += ft_putchar(remainder + '0');
		}
		else
		{
			ft_putnbr_hex(vartab, nb, converter);
			vartab->len += ft_putchar(remainder + ((converter - 23) - 10));
		}
	}
	else if (nb > 9 && nb < 16)
		vartab->len += ft_putchar(nb + ('a' - 10));
	else
		vartab->len += ft_putchar(nb + '0');
}
