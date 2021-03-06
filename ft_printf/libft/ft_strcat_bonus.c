/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:48:53 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/14 16:24:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
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
