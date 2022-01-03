/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:53:38 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/30 11:47:41 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static	int	check_max_long(unsigned long long int result, int sign)
{
	if (result == MAX_LONG && sign == -1)
		return (1);
	else if (result > MAX_LONG && sign == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
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
	if (*str)
		return (0);
	if ((result == MAX_LONG && !(*str)) || result > MAX_LONG)
		return (check_max_long(result, sign));
	return ((int)result * sign);
}
