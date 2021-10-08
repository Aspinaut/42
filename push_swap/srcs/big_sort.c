/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:05:10 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/08 12:47:23 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void set_positions(t_stack *stack_a)
{
	t_stack *st_cpy;
	t_stack *a_head;
	int i;

	i = 0;
	st_cpy = stack_cpy(stack_a);
	if (!st_cpy)
		return ;
	quicksort(st_cpy, st_cpy);
	while (st_cpy)
	{
		a_head = stack_a;
		while (a_head)
		{
			if (a_head->nb == st_cpy->nb)
			{
				a_head->pos = i++;
				break ;
			}
			a_head = a_head->next;
		}
		st_cpy = st_cpy->next;
	}
	stack_clear(&st_cpy);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	i = 0;
	set_positions(*a);
	while (a && *a && !sorted(*a))
	{
		size = stack_size(*a);
		while (a && *a && size--)
		{
			if ((((*a)->pos >> i) & 1))
				rotate(a, 'a');
			else
			{
				push(b, (*a)->nb, 'b');
				stack_delone(a);
			}
		}
		while (*b)
		{
			push(a, (*b)->nb, 'a');
			stack_delone(b);
		}
		i++;
	}
}
