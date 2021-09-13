/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 16:54:52 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void free_child(t_child *child)
{
  free(child->cmd_args);
  free(child->cmd_path);
}

void init_child(t_child *child, int pfd[2], int fd, char **envp)
{
  if (fd == 3)
  {
    child->id = 1;
    child->file_pos = 1;
    child->cmd_pos = 2;
  }
  else if (fd == 4)
  {
    child->id = 2;
    child->file_pos = 4;
    child->cmd_pos = 3;
  }
  child->pid = 0;
  child->fd = fd;
  child->pfd[0] = pfd[0];
  child->pfd[1] = pfd[1];
  child->cmd_args = NULL;
  child->cmd_path = NULL;
  child->file = NULL;
}

void process_child_command(t_child child, char **envp, char **argv)
{
  char *env_paths_line;
  char **env_paths;
  int i;

  env_paths_line = find_env_paths(envp);
  env_paths = ft_split(env_paths_line, ':');
  // protection
  // !!! bien checker si argv[2] est vide
  child.cmd_args = ft_split(argv[child.cmd_pos], ' ');
  i = -1;
  while (env_paths[++i])
  {
    child.cmd_path = ft_strjoin(env_paths[i], "/");
    child.cmd_path = ft_strjoin(child.cmd_path, child.cmd_args[0]);
    if (access(child.cmd_path, F_OK | X_OK) != -1)
    {
      execve(child.cmd_path, child.cmd_args, envp);
    }
    else
    {
      // free(child.cmd_path);
    }
  // exit
  }
  free(env_paths_line);
  free(env_paths);
  free_child(&child);
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
  process_child_command(*child, envp, argv);
  // exit
  return (0);
}
