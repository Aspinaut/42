#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_canvas
{
    int     width;
    int     height;
    char    bg_char;
    char    **matrix;
}               t_canvas;

typedef struct s_rect
{

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

void ft_free(t_canvas canvas)
{
    int i = 0;

    while (i < canvas.width)
    {
      free(canvas.matrix[i]);
      i++;
    }
    free(canvas.matrix);
}

int add_info(t_canvas *canvas, FILE *file)
{
    int i = 0;
    int j;

    if (fscanf(file, "%d %d %c", &canvas->width, &canvas->height, &canvas->bg_char) == 3)
    {
        if (canvas->width < 1 || canvas->width > 300 || canvas->height < 1 || canvas->height > 300)
          return (0);
        canvas->matrix = malloc(sizeof(char *) * canvas->height + 1);
        if (!canvas->matrix)
          return (0);
        while (i < canvas->height)
        {
          canvas->matrix[i] = malloc(sizeof(char) * canvas->width + 1);
          if (!canvas->matrix[i])
            return (0);
          j = 0;
          while (j < canvas->width)
          {
            canvas->matrix[i][j] = canvas->bg_char;
            j++;
          }
          i++;
        }
        return (1);
    }
    return (0);
}

void    draw(t_canvas canvas)
{
    int i =0;
    int j =0;

    while (i < canvas.height)
    {
      j = 0;
      while (j < canvas.width)
      {
        write(1, &canvas.matrix[i][j], 1);
        j++;
      }
      write(1, "\n", 1);
      i++;
    }
}

int main(int argc, char **argv)
{
    t_canvas canvas;
    FILE *file;

    if (argc != 2)
        return (str_err("Error: argument\n", 1));
    if (!(file = fopen(argv[1], "r")))
        return (str_err("Error: Operation file corrupted\n", 1));
    if (!(add_info(&canvas, file)))
        return (str_err("Error: Operation file corrupted\n", 1));
    add_info(&canvas, file);
    draw(canvas);
    ft_free(canvas);
    fclose(file);
    return (0);
}
