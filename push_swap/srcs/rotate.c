/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:48:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/02 13:46:49 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*first;

	if (!*stack)
		return ;
	last = stack_last(*stack);
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	stack_addback(stack, first);
	last->next->prev = last;
	last->next->next = NULL;
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
