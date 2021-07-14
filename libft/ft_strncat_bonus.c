/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:43:55 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/14 16:25:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				j;
	int				dest_size;

	j = 0;
	i = -1;
	dest_size = ft_strlen(dest);
	while (++i < nb && src[j] != '\0')
	{
		dest[dest_size + j] = src[j];
		j++;
	}
	dest[dest_size + j] = '\0';
	return (dest);
}
