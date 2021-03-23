/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:42:48 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/15 18:32:23 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t 	i;
	unsigned char		*s1_buffer;
	unsigned char		*s2_buffer;

	i = 0;
	s1_buffer = (unsigned char *)s1;
	s2_buffer = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_buffer[i] != s2_buffer[i])
			return (s1_buffer[i] - s2_buffer[i]);
		i++;
	}
	return (0);
}
