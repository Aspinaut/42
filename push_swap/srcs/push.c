/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:57:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/18 11:20:46 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack, int nb, char c)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return ;
	if (!*stack)
	{
		*stack = temp;
		(*stack)->pos = nb;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = *stack;
		temp->pos = nb;
		(*stack)->prev = temp;
		*stack = temp;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push_small(t_stack **stack, int nb, char c)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return ;
	if (!*stack)
	{
		*stack = temp;
		(*stack)->nb = nb;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = *stack;
		temp->nb = nb;
		(*stack)->prev = temp;
		*stack = temp;
	}
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}
