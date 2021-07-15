/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:03:49 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/15 13:11:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc_substr(size_t size)
{
	void	*allocated_area;

	allocated_area = malloc(size);
	if (!allocated_area)
		return (NULL);
	ft_bzero(allocated_area, size);
	return (allocated_area);
}

static char	*ft_strnew_substr(size_t size)
{
	return ((char *)ft_memalloc_substr((size + 1) * (sizeof(char))));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sample;
	size_t	i;
	int		len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len_s < (int)start)
		return (ft_strdup(""));
	else if (len_s < ((int)start + (int)len))
		len = len_s - start;
	sample = ft_strnew_substr(len);
	if (!(sample))
		return (NULL);
	while (i < len)
	{
		sample[i] = s[start];
		start++;
		i++;
	}
	sample[i] = '\0';
	return (sample);
}
