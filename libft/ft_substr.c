/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:03:49 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/15 11:59:26 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc(size_t size)
{
	void	*allocated_area;

	allocated_area = malloc(size);
	if (!allocated_area)
		return (NULL);
	ft_bzero(allocated_area, size);
	return (allocated_area);
}

static char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc((size + 1) * (sizeof(char))));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sample;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	sample = ft_strnew(len);
	if (!(sample))
		return (NULL);
	while (i < len)
	{
		sample[i] = s[start];
		start++;
		i++;
	}
	return (sample);
}
