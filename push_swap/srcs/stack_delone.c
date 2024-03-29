/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:34:27 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/19 12:01:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_delone(t_stack **stack, int big_sort)
{
	t_stack	*to_del;
	t_stack	*head;

	if (!*stack)
		return ;
	to_del = *stack;
	head = *stack;
	while (to_del && to_del->pos != (*stack)->pos && big_sort)
		to_del = to_del->next;
	while (to_del && to_del->nb != (*stack)->nb && !big_sort)
		to_del = to_del->next;
	if (to_del->next)
		to_del->next->prev = to_del->prev;
	if (to_del->prev)
		to_del->prev->next = to_del->next;
	*stack = head;
	if (to_del == head)
		*stack = to_del->next;
	free(to_del);
}
