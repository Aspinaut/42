/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:32:07 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/19 15:29:16 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_cpy(t_stack *stack)
{
	t_stack	*new;

	if (!stack)
		return (NULL);
	// new = stack_addnew(stack->nb);
	// if (!new)
	// 	return (NULL);
	new = NULL;
	// stack = stack->next;
	while (stack)
	{
		// stack_addback(&new, stack_addnew(stack->nb), new);
		new_stack(&new, stack->nb);
		stack = stack->next;
	}
	return (new);
}
