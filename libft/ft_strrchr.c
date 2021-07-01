/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:48:33 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/01 10:39:46 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen((char *)s);
	if (c == '\0' && c == s[len_s])
	{
		return ((char *)s + len_s);
	}
	while (len_s >= 0)
	{
		if (*(s + len_s) == (char)c)
			return ((char *)s + len_s);
		len_s--;
	}
	return (NULL);
}
