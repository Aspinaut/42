/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:05:10 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/06 11:41:57 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	i = 0;
	while (a && *a && !sorted(*a))
	{
		size = stack_size(*a);
		while (a && *a && size--)
		{
			if ((((*a)->nb >> i) & 1))
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
