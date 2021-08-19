/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/19 18:17:22 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned long	nbr;

	nbr = n;
	if (nbr >= 0 && nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr_unsigned(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	return (ft_strlen(ft_itoa((int)n)));
}