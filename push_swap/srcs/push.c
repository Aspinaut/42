/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:57:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/23 16:59:41 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_stack **stack_in, t_stack **stack_out, char c)
{
    if (!(*stack_in))
    {
        // si n nexiste pas, clear ??
        // pas sur de return error...
        exit(ft_putstr_fd("Error\n", 2));
    }
    if (!(*stack_out))
        (*stack_out) = stack_addnew((*stack_in)->nb);
    else 
        stack_addfront(stack_out, (*stack_in));
    if ((*stack_in)->next)
        stack_addfront(&(*stack_in), (*stack_in)->next);
    stack_delone(&(*stack_in));
    write(1, "p", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}