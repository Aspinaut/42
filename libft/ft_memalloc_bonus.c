/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:24:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/14 16:24:10 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*allocated_area;

	allocated_area = malloc(size);
	if (!allocated_area)
		return (NULL);
	ft_bzero(allocated_area, size);
	return (allocated_area);
}
