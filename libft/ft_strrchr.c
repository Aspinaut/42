/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:48:33 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/30 20:18:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while (len >= 0)
	{
		if (*(s + len) == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
