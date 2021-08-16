/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:15:40 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/03 17:34:42 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

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
