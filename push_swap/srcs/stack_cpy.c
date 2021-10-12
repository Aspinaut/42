/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:32:07 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/07 09:47:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_cpy(t_stack *stack)
{
	t_stack	*new_stack;

	if (!stack)
		return (NULL);
	new_stack = stack_addnew(stack->nb);
	if (!new_stack)
		return (NULL);
	stack = stack->next;
	while (stack)
	{
		stack_addback(&new_stack, stack_addnew(stack->nb));
		stack = stack->next;
	}
	return (new_stack);
}
