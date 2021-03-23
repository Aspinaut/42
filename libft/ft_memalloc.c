/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:18:00 by vmasse            #+#    #+#             */
/*   Updated: 2020/11/14 09:48:40 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  *ft_memalloc(size_t size)
{
  void *allocated_area;

  allocated_area = malloc(size);
  if(!allocated_area)
    return (NULL);
  ft_bzero(allocated_area, size);
  return (allocated_area);
}
