/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:25 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 13:26:42 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int child_one_process(t_child child1, char **envp, char **argv)
{
  char *cmd_path;
  char **cmd_args;
  // char *env_path;
  // char **env_paths;

  dup2(fd1, STDIN_FILENO);
  dup2(pfd[1], STDOUT_FILENO);
  close(pfd[0]);
  close(fd1);

  // protection
  // !!! bien checker si argv[2] est vide
  cmd_args = ft_split(argv[2], ' ');
  // env_path = ft_substr(strncmp(envp));
  cmd_path = "/usr/bin/ls";
  if (access(cmd_path, F_OK | X_OK) != -1)
    execve(cmd_path, cmd_args, envp);
  else
    perror("child");
  // exit
  return (0);
}

static int child_two_process(t_child child2, char **envp, char **argv)
{
  dup2(pfd[0], STDIN_FILENO);
  dup2(fd2, STDOUT_FILENO);
  close(pfd[1]);
  close(fd2);

  // protection
  char *cmd;
  char *cmdargs[2];
  cmdargs[0] = "cat";
  cmdargs[1] = NULL;
  cmd = "/usr/bin/cat";
  if (access(cmd, F_OK | X_OK) != -1)
  {
    execve(cmd, cmdargs, envp);
    perror("ici");
  }
  else
    perror("child");
  // exit
  return (0);
}

static int parent_process(int *pfd)
{
  int status;

  // protection
  status = 0;
  waitpid(-1, &status, 0);
  close(pfd[0]);
  close(pfd[1]);
  perror("parent");
  // exit
  return (0);
}

void pipex(int fd1, int fd2, char **envp, char **argv)
{
  int pfd[2];
  t_child child1;
  t_child child2;

  pipe(pfd);
  init_t_child(&child1, pfd);
  child1.id = fork();
  if (child1.id < 0)
    return (perror("Fork child one: "));
  else if (child1.id == 0)
    child_one_process(child1, envp, argv);
  init_t_child(&child2, pfd);
  child2.id = fork();
  if (child2.id < 0)
    return (perror("Fork child two: "));
  else if (child2.id == 0)
    child_two_process(child2, envp, argv);
  parent_process(pfd);
}

int main(int argc, char **argv, char **envp)
{
  int fd1;
  int fd2;
  char *env_paths;

  if (argc != 5)
    return (-1);
  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[4], O_RDWR | O_CREAT);
  if (fd1 < 0 || fd2 < 0)
    return (-1);
  env_paths = find_env_paths(envp);
  // protection env paths ??
  pipex(fd1, fd2, envp, argv);
  close(fd1);
  close(fd2);
  free(env_paths);
  return (0);
}
