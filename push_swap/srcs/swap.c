/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:29 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/08 11:32:17 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, char c)
{
	int	nb_temp;

	nb_temp = stack->next->nb;
	stack->next->nb = stack->nb;
	stack->nb = nb_temp;
	if (c != ' ')
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, ' ');
	swap(stack_b, ' ');
	write(1, "ss\n", 3);
}
