/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:58:30 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/04 16:51:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *src)
{
	char	*string;
	int		src_size;
	int		i;

	i = 0;
	src_size = ft_strlen(src);
	string = malloc(sizeof(char) * (src_size + 1));
	if (!(string))
	{
		return (NULL);
	}
	while (i < src_size)
	{
		string[i] = src[i];
		i++;
	}
	string[src_size] = '\0';
	return (string);
}
