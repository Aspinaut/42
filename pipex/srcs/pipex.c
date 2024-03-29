/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:25 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/15 11:50:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/libft.h"

static void	parent_process(t_child *child1, t_child *child2, int *pfd, char **e)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	close(pfd[0]);
	close(pfd[1]);
	free_child(child1);
	free_child(child2);
	ft_free(e);
}

void	pipex(int fd1, int fd2, char **envp, char **argv)
{
	t_child	child1;
	t_child	child2;
	char	**env_paths;
	int		pfd[2];

	pipe(pfd);
	env_paths = get_env_paths(envp);
	if (!env_paths)
		exit(EXIT_FAILURE);
	init_child(&child1, pfd, fd1, env_paths);
	child1.pid = fork();
	if (child1.pid < 0)
		exit(EXIT_FAILURE);
	else if (child1.pid == 0)
		child_process(&child1, envp, argv, env_paths);
	init_child(&child2, pfd, fd2, env_paths);
	child2.pid = fork();
	if (child2.pid < 0)
		exit(EXIT_FAILURE);
	else if (child2.pid == 0)
	{
		free_child(&child1);
		child_process(&child2, envp, argv, env_paths);
	}
	parent_process(&child1, &child2, pfd, env_paths);
}
