/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:48:56 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/02 17:39:19 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_max(t_stack **stack_a)
{
	int max;

	max = (*stack_a)->nb;
	while (*stack_a)
	{
		if ((*stack_a)->nb > max)
			max = (*stack_a)->nb;
		*stack_a = (*stack_a)->next;
	}
	return (max);
}

int find_min(t_stack **stack_a)
{
	int min;

	min = (*stack_a)->nb;
	while (*stack_a)
	{
		if ((*stack_a)->nb < min)
			min = (*stack_a)->nb;
		*stack_a = (*stack_a)->next;
	}
	return (min);
}

void small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int min;

	min = find_min(stack_a);
	if (stack_b)
		stack_clear(stack_b);
}
