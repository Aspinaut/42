/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:34:27 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/21 13:43:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_delone(t_stack *stack, void (*del)(int))
{
	if (!stack || !del)
		return ;
	del(stack->nb);
	free(stack);
}
