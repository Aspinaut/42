#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_rect
{
    int     width;
    int     height;
    char    bg_char;
}               t_rect;

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

void    draw(t_rect *rect, FILE *file)
{
    
}

int main(int argc, char **argv)
{
    t_rect rect;
    FILE *file;

    if (argc != 2)
        return (str_err("Error: argument\n", 1));
    if (!(file = fopen(argv[1], "r")))
        return (str_err("Error: Operation file corrupted\n", 1));
    draw(&rect, file);
    fclose(file);
    return (0);
}