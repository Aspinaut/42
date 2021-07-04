/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:07:49 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/04 17:15:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
  t_list *p;
  t_list *temp;

  if (!lst || !del)
    return ;
    p = (*lst);
  while (p->next)
  {
    temp = p;
    del(p);
    free(p);
    p = temp;
  }
  del(lst);
  free(lst);
}
