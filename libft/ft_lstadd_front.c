/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:30:07 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/23 14:52:44 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

typedef struct  s_list
{
  void *content;
  struct s_list *next;
}               t_list;


void ft_lstadd_front(t_list **lst, t_list *new) {

}

int main() {
  int i;
  t_list **list;

  i = 0;
  while (i < 3) {
    printf("%s", list[i]);
    i++;
  }
}
