/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:23:18 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/15 12:10:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc_join(size_t size)
{
	void	*allocated_area;

	allocated_area = malloc(size);
	if (!allocated_area)
		return (NULL);
	ft_bzero(allocated_area, size);
	return (allocated_area);
}

static char	*ft_strnew_join(size_t size)
{
	return ((char *)ft_memalloc_join((size + 1) * (sizeof(char))));
}

static int	is_inset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !set)
		return (NULL);
	while (is_inset(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && is_inset(set, s1[j]))
		j--;
	s2 = ft_strnew_join((j - i) + 1);
	if (!(s2))
		return (NULL);
	if (ft_strlen(s1) == i)
		return (ft_strdup(""));
	while (i <= j)
		s2[k++] = s1[i++];
	return (s2);
}
