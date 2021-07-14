/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:23:18 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/14 12:52:45 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	s2 = ft_strnew((j - i) + 1);
	if (!(s2))
		return (NULL);
	if (ft_strlen(s1) == i)
		return (ft_strdup(""));
	while (i <= j)
		s2[k++] = s1[i++];
	return (s2);
}
