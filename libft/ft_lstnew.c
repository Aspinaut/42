/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:27:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/23 14:20:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(link));
	if (!(link))
	{
		return (NULL);
	}
	link->content = content;
	link->next = NULL;
	return (link);
}
