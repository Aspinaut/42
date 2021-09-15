/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:59:22 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/15 11:50:21 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include "../includes/libft.h"

static int	empty_cmd(char *arg)
{
	int	i;

	i = -1;
	while (arg && arg[++i])
	{
		if (arg[i] != ' ')
			return (0);
	}
	return (1);
}

static int	return_empty_cmd(char **argv)
{
	if (!empty_cmd(argv[2]) && empty_cmd(argv[3]))
	{
		print_cmd_not_found(argv[3]);
		return (1);
	}
	else if (empty_cmd(argv[2]) && !empty_cmd(argv[3]))
	{
		print_cmd_not_found(argv[2]);
		return (1);
	}
	else if (empty_cmd(argv[2]) && empty_cmd(argv[3]))
	{
		print_cmd_not_found(argv[2]);
		print_cmd_not_found(argv[3]);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
		return (write(2, "Invalid number of arguments.\n", 29));
	if (return_empty_cmd(argv))
		return (-1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		return (ft_putstr_fd(strerror(errno), 2));
	pipex(fd1, fd2, envp, argv);
	if (close(fd1) < 0 || close(fd2) < 0)
		return (ft_putstr_fd(strerror(errno), 2));
	return (0);
}
