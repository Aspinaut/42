/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:48:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 12:54:49 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **s, char c)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s)
		return ;
	while (*s && (*s)->prev)
		*s = (*s)->prev;
	last = *s;
	if (!(*s)->next)
		return ;
	first = (*s)->next;
	*s = first;
	first->prev = 0;
	while (first && first->next)
		first = first->next;
	first->next = last;
	last->next = 0;
	last->prev = first;
	if (c != ' ')
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, ' ');
	rotate(stack_b, ' ');
	write(1, "rr\n", 3);
}
