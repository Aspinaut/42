/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:20:24 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/15 13:12:35 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc_strmapi(size_t size)
{
	void	*allocated_area;

	allocated_area = malloc(size);
	if (!allocated_area)
		return (NULL);
	ft_bzero(allocated_area, size);
	return (allocated_area);
}

static char	*ft_strnew_strmapi(size_t size)
{
	return ((char *)ft_memalloc_strmapi((size + 1) * (sizeof(char))));
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!f || !s)
		return (NULL);
	s2 = ft_strnew_strmapi(ft_strlen(s));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
