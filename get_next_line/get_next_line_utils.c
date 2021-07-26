/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:18:43 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/26 17:43:30 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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