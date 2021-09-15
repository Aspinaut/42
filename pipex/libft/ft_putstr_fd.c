/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:25:30 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/15 11:26:55 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (*s)
	{
		len += write(fd, s, 1);
		s++;
	}
	return (len);
}
