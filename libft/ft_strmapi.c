/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:20:24 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/17 18:47:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  char    *s2;
  size_t  i;

  i = 0;
  if (!f || !s)
    return (NULL);
  if (!(s2 = ft_strnew(ft_strlen((char *)s))))
    return (NULL);
  while (s[i])
  {
    s2[i] = (*f)(i, s[i]);
    i++;
  }
  s2[i] = '\0';
  return (s2);
}
