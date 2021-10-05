/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:24:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/05 10:25:39 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_max(t_stack **stack)
{
	int max;

	max = (*stack)->nb;
	while (*stack)
	{
		if ((*stack)->nb > max)
			max = (*stack)->nb;
		*stack = (*stack)->next;
	}
	return (max);
}

int find_min(t_stack **stack)
{
	int min;

	min = (*stack)->nb;
	while (*stack)
	{
		if ((*stack)->nb < min)
			min = (*stack)->nb;
		*stack = (*stack)->next;
	}
	return (min);
}

int sorted(t_stack **stack)
{
	while ((*stack))
	{
		if ((*stack)->next && (*stack)->nb > (*stack)->next->nb)
			return (0);
		(*stack) = (*stack)->next;
	}
	return (1);
}
