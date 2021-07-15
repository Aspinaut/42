/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:10:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/15 11:55:30 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(dest);
	while (src[++i] != '\0')
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
	return (dest);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2));
	if (!(s3))
		return (NULL);
	ft_strcpy(s3, (char *)s1);
	ft_strcat(s3, (char *)s2);
	return (s3);
}
