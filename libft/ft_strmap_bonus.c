/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:20:09 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/14 16:25:07 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*s2;
	size_t		i;

	i = 0;
	if (!f || !s)
		return (NULL);
	s2 = ft_strnew(ft_strlen((char *)s));
	if (!(s2))
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
