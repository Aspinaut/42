/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:48:56 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/06 10:43:38 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void put_two_shortest_in_b(t_stack **stack_a, t_stack **stack_b)
{
	int min;
	int i;

	min = find_min(*stack_a);
	i = 0;
	while (*stack_a && (*stack_a)->nb != min)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	if (i == 0)
	{
		push(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 1)
	{
		swap(stack_a, 'a');
		push(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 2)
	{
		rotate(stack_a, 'a');
		swap(stack_a, 'a');
		push(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 3)
	{
		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
		push(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 4)
	{
		reverse_rotate(stack_a, 'a');
		push(stack_b, (*stack_a)->nb, 'b');
	}
}

void small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int stop;

	stop = -1;
	while (!sorted(*stack_a) && ++stop < 2)
		put_two_shortest_in_b(stack_a, stack_b);
	if (stack_b)
	{
		while ((*stack_b))
		{
			push(stack_a, (*stack_b)->nb, 'a');
			if (!(*stack_b)->next)
				break ;
			(*stack_b) = (*stack_b)->next;
		}
		stack_clear(stack_b);
	}
}
