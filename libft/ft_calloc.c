/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:44:41 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/17 10:14:42 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  *ft_calloc(size_t nmemb, size_t size)
{
  void *dest;

	if (!(dest = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
