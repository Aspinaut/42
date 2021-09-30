/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:57:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/30 15:46:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_stack **s, t_stack **stack_out, char c)
{
    // if (!(*stack_in))
    // {
    //     // si n nexiste pas, clear ??
    //     // pas sur de return error...
    //     exit(ft_putstr_fd("Error\n", 2));
    // }
    // if (!(*stack_out))
    //     (*stack_out) = stack_addnew((*stack_in)->nb);
    // else
    //     stack_addfront(stack_out, (*stack_in));
    // if ((*stack_in)->next)
    //     stack_addfront(&(*stack_in), (*stack_in)->next);
    // stack_delone(&(*stack_in));
	t_stack	*top;

	top = malloc(sizeof(t_stack));
	if (!top)
		return ;
	if (*s == NULL)
	{
		*s = top;
		(*s)->nb = (*stack_out)->nb;
		(*s)->prev = 0;
		(*s)->next = 0;
	}
	else
	{
		write(1, "a", 1);
		top->prev = 0;
		top->next = *s;
		top->nb = (*stack_out)->nb;
		(*s)->prev = top;
		*s = top;
	}
	stack_delone(stack_out);
    write(1, "p", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}
