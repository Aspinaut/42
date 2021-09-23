/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:29 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/23 10:52:31 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack, char c)
{
    t_stack *p;
    int n_temp;

    p = (*stack);
    if (!p || !p->next)
    {
        // attention si jamais on est sur b et que b nexiste pas, on doit liberer a aussi
        stack_clear(&p);
        exit(ft_putstr_fd("Error\n", 2));
    }
    n_temp = p->next->nb;
    p->next->nb = p->nb;
    p->nb = n_temp;
    if (c != ' ')
    {
        write(1, "s", 1);
        write(1, &c, 1);
        write(1, "\n", 1);
    }
}

void swap_both(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a, ' ');
    swap(stack_b, ' ');
    write(1, "ss\n", 3);
}