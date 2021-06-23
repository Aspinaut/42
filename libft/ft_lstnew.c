/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:27:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/23 14:20:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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

int main(){
  t_list Obj;
  Obj = ft_lstnew("Salut");
  printf("%s", Obj.content);
}
