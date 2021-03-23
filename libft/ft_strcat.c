/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 08:48:53 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/10 14:35:22 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int nb;

	i = -1;
	nb = ft_strlen(dest);
	while (src[++i] != '\0')
	{
		dest[nb + i] = src[i];
	}
	dest[nb + i] = '\0';
	return (dest);
}
