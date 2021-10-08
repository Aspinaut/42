/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_addnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:53:45 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/08 15:11:39 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_addnew(int nb)
{
	t_stack	*link;

	link = (t_stack *)malloc(sizeof(t_stack));
	if (!link)
		return (NULL);
	link->pos = 0;
	link->nb = nb;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}
