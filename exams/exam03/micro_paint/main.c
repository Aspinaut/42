#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_params
{
    int width;
    int height;
}               t_params;

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

int str_err(char *err, int ret)
{
    write(1, err, ft_strlen(err));
    return (ret);
}

int read_file(char *filename)
{

    return (1);
}

int main(int argc, char **argv)
{
    t_params rect;

    if (argc != 2)
        return (str_err("Error: argument\n", 1));
    if (!read_file(argv[1]))
        return (str_err("Error: Operation file corrupted\n", 1));
    return (0);
}