/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:21:29 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/23 10:08:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack, char c)
{
    t_stack *p;
    int n_temp;

    p = (*stack);
    n_temp = p->next->nb;
    p->next->nb = p->nb;
    p->nb = n_temp;
    write(1, "s", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}