/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:25 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/11 19:36:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int child_process(int *pfd, int fd1, char **envp)
{
  // READ WITH CMD1(INFILE1)
  // WRITE TO fd[1]'s sub process

  dup2(fd1, STDIN_FILENO);
  dup2(pfd[1], STDOUT_FILENO);
  close(pfd[0]);
  close(fd1);

  char *cmdargs[2];
  cmdargs[0] = "-la";
  cmdargs[1] = NULL;

  execve("/usr/bin/ls", cmdargs, envp);
  perror("child");

  return (0);
}

int parent_process(int *pfd, int fd2, char **envp)
{
  // READ WITH CMD2(fd[2])
  // WRITE TO fd[1]'s sub process

  int status;

  // parent has to wait for child with waitpid()
  status = 0;
  waitpid(-1, &status, 0);
  dup2(pfd[0], STDIN_FILENO);
  dup2(fd2, STDOUT_FILENO);
  close(pfd[1]);
  close(fd2);

  char *cmdargs[2];
  cmdargs[0] = "cat";
  cmdargs[1] = NULL;

  execve("/usr/bin/cat", cmdargs, envp);
  perror("parent");

  return (0);
}

void pipex(int fd1, int fd2, char **envp)
{
    int pfd[2];
    pid_t task;

    pipe(pfd); // pipe init vfd à [0, 1]
    task = fork();
    if (task < 0)
        return ;
    else if (!task)
    {
        child_process(pfd, fd1, envp);
    }
    else
    {
        parent_process(pfd, fd2, envp);
    }

}

int main(int argc, char **argv, char **envp)
{
    // READ from infile
    // EXECUTE cmd1 with infile as input
    // SEND output to cmd2
    // WRITE to outfile

    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[4], O_RDWR | O_CREAT);

    pipex(fd1, fd2, envp);

    close(fd1);
    close(fd2);

    return (0);
}
