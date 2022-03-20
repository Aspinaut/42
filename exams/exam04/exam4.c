#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <aio.h>
#include <wait.h>

size_t ft_strlen(char *s)
{
	size_t i = 0;

	while (s[i])
		i++;
	return (i);
}

void put_err(char *err, char *path)
{
	write(2, err, ft_strlen(err));
	if (path)
	{
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
	}
	exit(1);
}

char **subargv(char **argv, int start, int end)
{
	char **res;
	int i;

	res = malloc(sizeof(char *) * (end - start + 1));
	if (!res)
		return NULL;
	i = 0;
	while (start < end)
		res[i++] = argv[start++];
	res[i] = NULL;
	return (res);
}

int main(int argc, char **argv, char **envp)
{
	int i, pos_semicolon, start, end;
	int fd[2], fd_in;
	pid_t pid;
	char **av;

	// on boucle sur argc
		// on choppe la pos du semicolon 
		// on boucle jusqu'a cette pos pour aller jusqu'au next cmds_node
			// on set end à start
			// et on le set en se déplacant jusqu'au next pipe
			// on slice la tranche d'argv qui concerne cmds_node
			// on forke
			// on dup2 fd_in et fd[1]
			// on close les fds
			// gestion cd
			// sinon on appelle execve
		

	// on boucle sur argc
	i = 1;
	while (i < argc)
	{
		// on init toutes les variables
		pos_semicolon = end = start = i;
		// on choppe la pos du semicolon 
		while (pos_semicolon < argc && strcmp(argv[pos_semicolon], ";"))
			pos_semicolon++;
		// on boucle jusqu'a cette pos pour aller jusqu'au next cmds_node
		fd_in = 0;
		while (start < pos_semicolon)
		{
			// on set end à start
			end = start;
			// et on le set en se déplacant jusqu'au next pipe
			while (end < pos_semicolon && strcmp(argv[end], "|"))
				end++;
			// on slice la tranche d'argv qui concerne cmds_node
			av = subargv(argv, start, end);
			if (pipe(fd) == -1)
				put_err("error: fatal\n", NULL);
			// on forke
			pid = fork();
			if (pid == -1)
				put_err("error: fatal\n", NULL);
			else if (pid == 0)
			{
				// on dup2 fd_in et fd[1]
				if (dup2(fd_in, 0) == -1)
					put_err("error: fatal\n", NULL);
				if (end < pos_semicolon && dup2(fd[1], 1) == -1)
					put_err("error: fatal\n", NULL);
				// on close les fds
				close(fd_in);
				close(fd[0]);
				close(fd[1]);
				// gestion cd
				if (!strcmp(av[0], "cd"))
				{
					if (end - start !=2)
						put_err("error: fatal\n", NULL);
					if (chdir(av[1]))
						put_err("error: fatal\n", NULL);
				}
				// sinon on appelle execve
				else if (execve(av[0], av, envp))
					put_err("error: fatal\n", NULL);
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
		close(fd_in);
		i = pos_semicolon + 1;
	}
	return (0);
}