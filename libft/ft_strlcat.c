/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:57:35 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/18 18:31:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	copied_len;
	unsigned int	i;
	int				j;
	int				dest_size;
	size_t n;

	j = 0;
	i = -1;
	n = size - ft_strlen(dest) - 1;
	dest_size = ft_strlen(dest);
	while (++i < n && src[j] != '\0')
	{
		dest[dest_size + j] = src[j];
		j++;
	}
	dest[dest_size + j] = '\0';
	copied_len = ft_strlen((char *)src) + n;
	return (copied_len);
}
