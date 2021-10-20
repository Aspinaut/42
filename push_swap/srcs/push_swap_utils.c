/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:24:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 12:25:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

int	sorted(t_stack *stack, int big_sort)
{
	if (big_sort)
	{
		while (stack)
		{
			if (stack->next && stack->pos > stack->next->pos)
				return (0);
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (stack->next && stack->nb > stack->next->nb)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

void	quicksort(t_stack *stack_a, t_stack *head)
{
	while (stack_a)
	{
		if (stack_a->next && stack_a->nb > stack_a->next->nb)
		{
			swap(stack_a, ' ');
			stack_a = head;
		}
		else if (!stack_a->next)
			return ;
		else
			stack_a = stack_a->next;
	}
}
