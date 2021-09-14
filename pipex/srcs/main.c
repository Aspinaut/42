/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:59:22 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/14 18:32:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
		return (write(2, "Invalid number of arguments.\n", 29));
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		return (ft_putstr_fd(strerror(errno), 2));
	pipex(fd1, fd2, envp, argv);
	if (close(fd1) < 0 || close(fd2) < 0)
    return (ft_putstr_fd(strerror(errno), 2));
	return (0);
}
