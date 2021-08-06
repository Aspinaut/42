/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 08:31:51 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/06 08:32:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **ag)
{
  char *s;
  int fd;

  fd = open(ag[1], O_RDONLY);
  s = get_next_line(fd);
  while (s && s[0])
  {
    printf("|%s", s);
    ft_free(s);
    s = get_next_line(fd);
  }
  printf("|%s", s);
  ft_free(s);
  close(fd);
  system("leaks gnl");
  return (0);
}