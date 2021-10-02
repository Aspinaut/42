/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:57:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/02 12:07:59 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push(t_stack **s, int nb, char c)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return ;
	if (!*s)
	{
		*s = temp;
		(*s)->nb = nb;
		(*s)->prev = 0;
		(*s)->next = 0;
	}
	else
	{
		temp->prev = 0;
		temp->next = *s;
		temp->nb = nb;
		(*s)->prev = temp;
		*s = temp;
	}
    write(1, "p", 1);
    write(1, &c, 1);
    write(1, "\n", 1);
}
