/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:39:09 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/21 14:27:03 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while ((*stack))
	{
		temp = (*stack)->next;
		free((*stack));
		(*stack) = temp;
	}
}
