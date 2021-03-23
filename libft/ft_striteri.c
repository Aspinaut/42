/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:19:51 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/14 10:05:30 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_striteri(char *s, void (*f)(unsigned int, char *))
{
  unsigned int i;

  if (!s)
    return ;
  i = 0;
  while (s[i])
  {
    (*f)(i, &s[i]);
    i++;
  }
}
