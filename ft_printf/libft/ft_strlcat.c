/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:57:35 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/29 15:42:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	j;
	size_t	i;

	len_src = ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	len_dst = i;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	if (len_dst < size)
		dst[len_dst + len_src] = '\0';
	return (len_dst + len_src);
}
