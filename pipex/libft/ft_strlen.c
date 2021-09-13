/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:15:19 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 09:30:50 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen(const char *str)
{
	int	count;

  count = 0;
  if (!str)
    return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}
