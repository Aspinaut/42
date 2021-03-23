/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:18:53 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/14 08:57:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_putstr_fd(char const *s, int fd)
{
  if (!s)
    return ;
  while (*s)
  {
    write(fd, s, 1);
    s++;
  }
}
