/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:25 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 18:40:17 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int parent_process(int *pfd)
{
  int status;

  // protection
  status = 0;
  waitpid(-1, &status, 0);
  close(pfd[0]);
  close(pfd[1]);
  // exit
  return (0);
}

void pipex(int fd1, int fd2, char **envp, char **argv)
{
  int pfd[2];
  t_child child1;
  t_child child2;

  pipe(pfd);
  // quid d'un malloc non initialisé on top ?
  // protection env paths ??
  // free env paths dans la structure ??
  init_child(&child1, pfd, fd1);
  child1.pid = fork();
  if (child1.pid < 0)
    return (perror("Fork child one: "));
  else if (child1.pid == 0)
  {
    child_process(&child1, envp, argv);
  }
  init_child(&child2, pfd, fd2);
  child2.pid = fork();
  if (child2.pid < 0)
    return (perror("Fork child two: "));
  else if (child2.pid == 0)
  {
    child_process(&child2, envp, argv);
  }
  parent_process(pfd);
}
