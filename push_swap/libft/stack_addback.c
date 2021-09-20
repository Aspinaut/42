/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_addback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:53:29 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/20 15:53:35 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	stack_addback(t_stack **alst, t_stack *new)
{
	t_stack	*p;

	if (!alst || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		p = (*alst);
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
