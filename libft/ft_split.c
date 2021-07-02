/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:21:30 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/02 16:36:54 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int count_elem_len(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}
//
// static char *fill_current_arr(char const *s, char *arr, int nb_elems, int i)
// {
// 	int j;
//
// 	j = 0;
// 	while (j < nb_elems)
// 	{
// 		arr[j] = s[i];
// 		i++;
// 		j++;
// 	}
// 	arr[j] = '\0';
// 	return (arr);
// }

static char **fill_arr(char const *s, char **arr, char c)
{
	int i;
	int j;
	int k;
	int elem_len;

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
			{
				arr[j][k] = s[i];
				k++;
				i++;
			}
			arr[j][k] = '\0';
			j++;
		}
		i++;
	}
		// printf("%s\n", arr[j]);
	return(arr);
}

char **ft_split(char const *s, char c)
{
  char **arr;
  int nb_elems;
	int i;

	// compte mots
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb_elems++;
		i++;
	}

  arr = (char **)malloc(nb_elems * sizeof(char *) + 1);
  if (!arr)
    return (NULL);
	arr[nb_elems] = 0;

	arr = fill_arr(s, arr, c);
	// i = 0;
	// j = 0;
	// while (s[i])
	// {
	// 	if (s[i] != c)
	// 	{
	// 		elem_len = count_elem_len(s, c, i);
	// 		arr[j] = (char *)malloc(elem_len * sizeof(char) + 1);
	// 		if (!*arr)
	// 	    return (NULL);
	// 		arr[j] = fill_current_arr(s, *arr, elem_len, i);
	// 		printf("%s\n", arr[j]);
	// 		j++;
	// 		i += (elem_len - 1);
	// 	}
	// 	i++;
	// }
  return (arr);
}

// int main()
// {
//   char const *s =  "      split       this for   me  !       ";
//   char **arr;
//   int i = 0;
//
//   arr = ft_split(s, ' ');
// 	while (i < 5)
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
//
// }
