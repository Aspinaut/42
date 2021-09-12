/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:25 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/12 19:59:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void process_command()
{

}

int child_one_process(int *pfd, int fd1, char **envp)
{
  dup2(fd1, STDIN_FILENO);
  dup2(pfd[1], STDOUT_FILENO);
  close(pfd[0]);
  close(fd1);

  // protection
  char *cmd;
  char *cmdargs[2];
  cmdargs[0] = "-la";
  cmdargs[1] = NULL;
  cmd = "/usr/bin/ls";
  if (access(cmd, F_OK | X_OK) != -1)
    execve(cmd, cmdargs, envp);
  else
    perror("child");
  // exit
  return (0);
}

int child_two_process(int *pfd, int fd2, char **envp)
{
  dup2(pfd[0], STDIN_FILENO);
  dup2(fd2, STDOUT_FILENO);
  close(pfd[1]);
  close(fd2);

  // protection
  char *cmd;
  char *cmdargs[2];
  cmdargs[0] = "-e";
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

int parent_process(int *pfd)
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

void pipex(int fd1, int fd2, char **envp)
{
  int pfd[2];
  pid_t child1;
  pid_t child2;

  pipe(pfd);
  child1 = fork();
  if (child1 < 0)
    return (perror("Fork: "));
  else if (child1 == 0)
    child_one_process(pfd, fd1, envp);
  child2 = fork();
  if (child2 < 0)
    return (perror("Fork: "));
  else if (child2 == 0)
    child_two_process(pfd, fd2, envp);
  parent_process(pfd);
}

int main(int argc, char **argv, char **envp)
{
  int fd1;
  int fd2;

  // protection args
  fd1 = open(argv[1], O_RDONLY);
  fd2 = open(argv[4], O_RDWR | O_CREAT);
  if (fd1 < 0 || fd2 < 0)
    return (-1);
  pipex(fd1, fd2, envp);
  close(fd1);
  close(fd2);
  return (0);
}
