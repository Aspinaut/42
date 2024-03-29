/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:06:56 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/21 11:41:20 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	check_max_long(unsigned long long int result, int sign)
{
	if (result == MAX_LONG && sign == -1)
		return (1);
	else if (result > MAX_LONG && sign == -1)
		return (0);
	return (-1);
}

long	ft_atol(const char *str)
{
	unsigned long long int		result;
	int							sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if ((result == MAX_LONG && !(*str)) || result > MAX_LONG)
		return (check_max_long(result, sign));
	return (result * sign);
}
