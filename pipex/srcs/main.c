/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:59:22 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 14:59:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
  int fd1;
  int fd2;

  if (argc != 5)
    return (-1);
  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[4], O_RDWR | O_CREAT);
  if (fd1 < 0 || fd2 < 0)
    return (-1);
  pipex(fd1, fd2, envp, argv);
  close(fd1);
  close(fd2);
  return (0);
}
