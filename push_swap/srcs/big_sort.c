/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:05:10 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/16 18:46:10 by vmasse           ###   ########.fr       */
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
		if (!st_cpy->next)
			break ;
		st_cpy = st_cpy->next;
	}
	while (st_cpy)
	{
		printf("here\n" );
		st_cpy = st_cpy->prev;
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
		while (size)
		{
			// printf("size %d\n", (*a)->pos);
			if ((((*a)->pos >> i) & 1))
				rotate(a, 'a');
			else
			{
				push(b, (*a)->pos, 'b');
				stack_delone(a);
			}
			size--;
		}
		while (*b)
		{
			// printf("b %d\n", (*b)->pos);
			push(a, (*b)->pos, 'a');
			stack_delone(b);
		}
		// printf("STACK : %d\n", (*a)->);
		// stack_clear(b);
		i++;
	}
}
