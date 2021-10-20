/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:48:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 11:36:59 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **s, char c)
{
	// t_stack	*last;
	// t_stack	*first;
	//
	// if (!*stack)
	// 	return ;
	// last = stack_last(*stack);
	// last->prev->next = NULL;
	// first = *stack;
	// stack_addfront(stack, last);
	// // (*stack)->prev = NULL;
	// first->prev = NULL;
	// (*stack)->next = first;
	// if (c != ' ')
	// {
	// 	write(1, "rr", 2);
	// 	write(1, &c, 1);
	// 	write(1, "\n", 1);
	// }
	t_stack	*first;
	t_stack	*last;

	if (!*s)
		return ;
	while (*s && (*s)->next)
		*s = (*s)->next;
	last = *s;
	if (!(*s)->prev)
		return ;
	last->prev->next = 0;
	first = (*s)->prev;
	*s = last;
	while (first && first->prev)
		first = first->prev;
	first->prev = last;
	last->next = first;
	last->prev = 0;
	if (c != ' ')
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, ' ');
	reverse_rotate(stack_b, ' ');
	write(1, "rrr\n", 4);
}
