/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:34:27 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/23 15:39:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_delone(t_stack **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free((*stack));
}
