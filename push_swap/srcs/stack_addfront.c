/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_addfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:38:24 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/23 13:45:45 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_addfront(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = (*stack);
	new->prev = NULL;
	(*stack) = new;
}
