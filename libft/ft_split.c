/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:21:30 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/03 11:13:26 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_elems(char const *s, char c)
{
	int	i;
	int	nb_elems;

	nb_elems = 0;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb_elems++;
		i++;
	}
	return (nb_elems);
}

static	int	count_elem_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static	char	**fill_arr(char const *s, char **arr, char c)
{
	int	i;
	int	j;
	int	k;
	int	elem_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			elem_len = count_elem_len(s, c, i);
			arr[j] = (char *)malloc(elem_len * sizeof(char) + 1);
			if (!arr[j])
				return (NULL);
			while (s[i] != c)
				arr[j][k++] = s[i++];
			arr[j][k] = '\0';
			j++;
		}
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		nb_elems;

	nb_elems = count_elems(s, c);
	arr = (char **)malloc(nb_elems * sizeof(char *) + 1);
	if (!arr)
		return (NULL);
	arr[nb_elems] = 0;
	arr = fill_arr(s, arr, c);
	return (arr);
}
