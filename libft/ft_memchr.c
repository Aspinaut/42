/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:11:36 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/15 17:30:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char		*s_buffer;

	s_buffer = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s_buffer[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
