/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:19:31 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/14 09:58:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void add_one_to_char(char *c)
{
    if (*c == 'o')
      write(1, "h", 1);
    else
      write(1, c, 1);
}

void  ft_striter(char *s, void (*f)(char *))
{
  if (!s)
    return ;
  while (*s)
  {
    (*f)(s++);
  }
}
