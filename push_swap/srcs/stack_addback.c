/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_addback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:53:29 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/19 15:09:01 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_addback(t_stack **astack, t_stack *new, t_stack *head)
{
	t_stack	*p;

	if (!astack || !new)
		return ;
	if (!*astack)
	{
		*astack = new;
		(*astack)->prev = head;
		(*astack)->prev->next = *astack;
	}
	else
	{
		p = (*astack);
		while (p->next)
			p = p->next;
		p->next = new;
		new->prev = p;
	}
}
