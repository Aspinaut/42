/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:18:53 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/20 10:21:14 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return (-1);
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	return (-1);
}
