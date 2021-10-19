/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_addnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:53:45 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/19 15:31:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_addnew(int nb)
{
	t_stack	*link;

	link = (t_stack *)malloc(sizeof(t_stack));
	if (!link)
		return (NULL);
	link->pos = 0;
	link->nb = nb;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

void	new_stack(t_stack **a, int value)
{
	t_stack	*curr;
	t_stack	*last;

	curr = malloc(sizeof(t_stack));
	if (!curr)
		return (stack_clear(a));
	curr->nb = value;
	curr->next = 0;
	curr->pos = 0;
	if (*a == NULL)
	{
		curr->prev = NULL;
		*a = curr;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = curr;
	curr->prev = last;
	return ;
}
