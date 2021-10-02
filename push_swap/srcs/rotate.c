/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:48:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/02 13:05:12 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rotate(t_stack **stack, char c)
{
	t_stack *last;
	t_stack *temp;

	if (!*stack)
		return ;
	last = stack_last(*stack);
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	stack_addback(stack, temp);
	last->next->prev = last;
	last->next->next = NULL;
	write(1, "r", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}
