/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:03:49 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/14 17:14:41 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_substr(char const *s, unsigned int start, size_t len)
{
  char    *sample;
  size_t  i;

  i = 0;
  if (!s)
    return (NULL);
  if (ft_strlen((char *)s) < (int)start)
    return (ft_strdup(""));
  if (!(sample = ft_strnew(len)))
    return (NULL);
  while (i < len)
  {
    sample[i] = s[start];
    start++;
    i++;
  }
  return (sample);
}
