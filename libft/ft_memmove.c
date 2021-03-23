/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:36:50 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/15 08:33:07 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char		*dest_buffer;
	char		*src_buffer;

	i = -1;
	dest_buffer = (char *)dest;
	src_buffer = (char *)src;
	if (!dest && !src)
		return (0);
	if (src < dest)
	{
		while (n-- > 0)
			dest_buffer[n] = src_buffer[n];
	}
	else
		while (++i < n)
			dest_buffer[i] = src_buffer[i];
	dest = (void *)dest_buffer;
	return (dest);
}
