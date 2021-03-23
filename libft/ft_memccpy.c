/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:21:27 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/15 16:53:26 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char		*dest_buffer;
	char		*src_buffer;

	i = -1;
	dest_buffer = (char *)dest;
	src_buffer = (char *)src;
	while (++i < n)
	{
		dest_buffer[i] = src_buffer[i];
		if ((unsigned char)src_buffer[i] == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
