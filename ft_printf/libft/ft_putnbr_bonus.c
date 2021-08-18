/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:50:52 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/18 12:50:26 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	long	nbr;
	static int		len;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		ft_putchar('-');
		len++;
	}
	if (nbr >= 0 && nbr < 10)
	{
		ft_putchar(nbr + '0');
		len++;
	}
	else
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
		len++;
	}
	return (len);
}
