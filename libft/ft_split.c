/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:21:30 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/30 18:50:06 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char **ft_split(char const *s, char c)
{
  char **arr;
  int pos_c;
  int len_s;
  int i;

  pos_c = 0;
  len_s = 0;
  i = 0;
  arr = malloc(2 * sizeof(char *));
  while (s[len_s])
  {
    if (s[len_s] == c && pos_c == 0)
      pos_c = len_s;
    len_s++;
  }
  arr[0] = (char *)malloc(pos_c * sizeof(char) + 1);
  arr[1] = (char *)malloc((i - pos_c) * sizeof(char) + 1);
  while (i < pos_c)
  {
    arr[0][i] = s[i];
    i++;
  }
  arr[0][i] = '\0';
  i = 0;
  while (pos_c < len_s)
  {
    arr[1][i] = s[pos_c];
    i++;
    pos_c++;
  }
  arr[1][i] = '\0';
  return (arr);
}

// int main()
// {
//   char const *s = "bonjour";
//   char **arr;
//   int i = 0;
//
//   arr = ft_split(s, 'o');
//   while (i < 2)
//   {
//     printf("%s\n", arr[i]);
//     i++;
//   }
// }
