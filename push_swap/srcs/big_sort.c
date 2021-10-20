/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:05:10 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 12:55:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_positions(t_stack *a_cpy, t_stack *stack_a)
{
	t_stack	*a_head;
	int		i;

	i = 0;
	while (a_cpy)
	{
		a_head = stack_a;
		while (a_head)
		{
			if (a_head->nb == a_cpy->nb)
			{
				a_head->pos = i++;
				break ;
			}
			a_head = a_head->next;
		}
		if (!a_cpy->next)
			break ;
		a_cpy = a_cpy->next;
	}
	while (a_cpy && a_cpy->prev)
		a_cpy = a_cpy->prev;
	stack_clear(&a_cpy);
}

static void	normalize_stack(t_stack *stack_a)
{
	t_stack	*a_cpy;

	a_cpy = stack_cpy(stack_a);
	if (!a_cpy)
		return ;
	quicksort(a_cpy, a_cpy);
	set_positions(a_cpy, stack_a);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	i = 0;
	normalize_stack(*a);
	while (a && *a && !sorted(*a, 1))
	{
		size = stack_size(*a);
		while (size--)
		{
			if ((((*a)->pos >> i) & 1))
				rotate(a, 'a');
			else
			{
				push(b, (*a)->pos, 'b');
				stack_delone(a, 1);
			}
		}
		while (*b)
		{
			push(a, (*b)->pos, 'a');
			stack_delone(b, 1);
		}
		i++;
	}
}
