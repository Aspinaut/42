/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:30:07 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/24 09:41:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct  s_list
{
  void *content;
  struct s_list *next;
}               t_list;

t_list * ft_lstnew(void const *content) {
  t_list * link;

  if (!(link = (t_list *)malloc(sizeof(link)))) {
    return NULL;
  }
  link->content = content;
  link->next = NULL;
  return link;
}

void ft_lstadd_front(t_list **lst, t_list *new) {
  t_list	*start;

  	if (!lst || !new)
  		return ;
  	start = new;
  	start->next = (*lst);
  	(*lst) = start;
}

int main() {
  t_list **list;
  t_list *new_element;


  // new_element = ft_lstnew("Salut");
  ft_lstadd_front(list, new_element);
  printf("%s", *list);
  // list.content = "Hello";
  // printf("%s %s", list.content, list2.content);
}
