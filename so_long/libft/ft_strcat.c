/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:38:40 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/13 17:38:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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