/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:25 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/09 12:26:52 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void pipex(int fd1, int fd2)
{
    int end[2];
    pid_t parent;

    pipe(end);
    parent = fork();
    if (parent < 0)
        return ;
    else if (!parent)
    {
        printf("child : %d\n", parent);

    }
    else
    {
        printf("parent : %d\n", parent);

    }

}

int main(int argc, char **argv)
{
    // READ from infile
    // EXECUTE cmd1 with infile as input
    // SEND output to cmd2
    // WRITE to outfile
    
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);
    char buffer[5];
    char *to_print;

    // pipex(fd1, fd2);
    read(fd1, buffer, 5);
    to_print = strdup(buffer);
    write(
        fd1,
        "hello",
        5
    );

    close(fd1);
    close(fd2);

    return (0);
}