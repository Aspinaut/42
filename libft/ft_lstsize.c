/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:35:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/03 17:48:57 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
  int size;

  if (!lst)
    return (0);
  size = 0;
  while (lst)
  {
    size++;
    lst = lst->next;
  }
  return (size);
}
