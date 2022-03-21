#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <aio.h>
#include <wait.h>

size_t ft_strlen(char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return i;
}

void	put_err(char *err, char *path)
{
	write(2, err, ft_strlen(err));
	if (path)
	{
		write(2, path, ft_strlen(path));
		write(1, "\n", 1);
	}
	exit(1);
}

char **subargv(char **argv, int start, int end)
{
	char **res;
	int i;

	res = malloc(sizeof(char *) * (end - start + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = argv[start++];
	res[i] = NULL;
	return res;
}

int	main(int argc, char **argv, char **envp)
{
	int pos_semicolon, i, start, end;
	int fd[2], fd_in;
	char **av;
	pid_t pid;

	i = 1;
	while (i < argc)
	{
		pos_semicolon = end = start = i;
		while (pos_semicolon < argc && strcmp(argv[pos_semicolon], ";"))
			pos_semicolon++;
		fd_in = 0;
		while (start < pos_semicolon)
		{
			end = start;
			while (end < pos_semicolon && strcmp(argv[end], "|"))
				end++;
			av = subargv(argv, start, end);
			if (pipe(fd) == -1)
				put_err("error: fatal\n", NULL);
			pid = fork();
			if (pid == -1)
				put_err("error: fatal\n", NULL);
			else if (pid == 0)
			{
				if (dup2(fd_in, 0) == -1)
					put_err("error: fatal\n", NULL);
				if (end < pos_semicolon && dup2(fd[1], 1) == -1)
					put_err("error: fatal\n", NULL);
				close(fd_in);
				close(fd[0]);
				close(fd[1]);
				if (!strcmp(av[0], "cd"))
				{
					if (end - start != 2)
						put_err("error: cd: bad arguments\n", NULL);
					if (chdir(av[1]))
						put_err("error: cd: cannot change directory to path_to_change\n", av[1]);
				}
				else if (execve(av[0], av, envp) == 0)
					put_err("error: cannot execute executable_that_failed\n", av[0]);
				free(av);
				exit(0);
			}
			else
			{
				waitpid(pid, NULL, 0);
				close(fd[1]);
				if (fd_in)
					close(fd_in);
				fd_in = fd[0];
				free(av);
			}
			start = end + 1;
		}
		i = pos_semicolon + 1;
	}
	return 0;
}
