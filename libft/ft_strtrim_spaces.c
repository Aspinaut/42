/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:23:18 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/14 07:48:14 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_strtrim_spaces(char const *s)
{
  char    *s2;
  size_t  spaces_nb;
  int     i;
  int     j;
  int     k;

  spaces_nb = 0;
  i = 0;
  while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
  {
    spaces_nb++;
    i++;
  }
  j = ft_strlen((char *)s) - 1;
  while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
  {
    spaces_nb++;
    j--;
  }
  s2 = ft_strnew(ft_strlen((char *)s) - spaces_nb);
  k = 0;
  while (i <= j)
    s2[k++] = s[i++];
  return (s2);
}
