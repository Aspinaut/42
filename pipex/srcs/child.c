/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 21:09:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void free_child(t_child *child)
{
  free(child->cmd_args);
  free(child->cmd_path);
  free(child->env_paths);
}

void init_child(t_child *child, int pfd[2], int fd, char **env_paths)
{
  if (fd == 3)
  {
    child->id = 1;
    child->cmd_pos = 2;
  }
  else if (fd == 4)
  {
    child->id = 2;
    child->cmd_pos = 3;
  }
  child->pid = 0;
  child->fd = fd;
  child->pfd[0] = pfd[0];
  child->pfd[1] = pfd[1];
  child->cmd_args = NULL;
  child->cmd_path = NULL;
  child->file = NULL;
  child->env_paths = env_paths;
}

void process_child_cmd(t_child child, char **envp, char **argv)
{
  int i;

  // protection
  // !!! bien checker si argv[2] est vide
  child.cmd_args = ft_split(argv[child.cmd_pos], ' ');
  i = -1;
  while (child.env_paths[++i])
  {
    child.cmd_path = ft_strjoin(child.env_paths[i], "/");
    child.cmd_path = ft_strjoin(child.cmd_path, child.cmd_args[0]);
    if (access(child.cmd_path, F_OK | X_OK) != -1)
    {
      execve(child.cmd_path, child.cmd_args, envp);
    }
  // exit
  }
  write(2, "bash: ", 6);
  write(2, child.cmd_args[0], ft_strlen(child.cmd_args[0]));
  write(2, " : command not found\n", 21);
  free_child(&child);
  exit(EXIT_FAILURE);
}

int child_process(t_child *child, char **envp, char **argv)
{
  if (child->id == 1)
  {
    dup2(child->fd, STDIN_FILENO);
    dup2(child->pfd[1], STDOUT_FILENO);
    close(child->pfd[0]);
    close(child->fd);
  }
  else if (child->id == 2)
  {
    dup2(child->pfd[0], STDIN_FILENO);
    dup2(child->fd, STDOUT_FILENO);
    close(child->pfd[1]);
    close(child->fd);
  }
  process_child_cmd(*child, envp, argv);
  // exit
  return (0);
}
