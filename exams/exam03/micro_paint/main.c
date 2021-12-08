#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define ZERO 0.00000000

typedef struct s_canvas
{
    int     width;
    int     height;
    char    bg_char;
    char    **matrix;
}               t_canvas;

typedef struct s_rect
{
  float     x; 
  float     y;
  float     width;
  float     height;
  char      c;
  char      mode;
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

    while (i < canvas.height)
    {
      free(canvas.matrix[i]);
      i++;
    }
    free(canvas.matrix);
}

int add_canvas_vars(t_canvas *canvas, FILE *file)
{
    int i = 0;
    int j;

    if (fscanf(file, "%d %d %c\n", &canvas->width, &canvas->height, &canvas->bg_char) == 3)
    {
        if (canvas->width < 1 || canvas->width > 300 || canvas->height < 1 || canvas->height > 300)
          return (0);
        canvas->matrix = malloc(sizeof(char *) * canvas->height);
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
          canvas->matrix[i][j] = '\n';
          i++;
        }
        return (1);
    }
    return (0);
}

void  write_matrix(t_canvas *canvas, t_rect rect)
{
  int x;
  int y;
  int height;
  int width;

  y = (int)rect.y;
  height = (int)rect.height;
  width = (int)rect.width;
  if (rect.mode == 'R')
  {
    while (y < (height + (int)rect.y) + 1)
    {
      x = (int)rect.x;
      while (x < (width + (int)rect.x))
      {
        fprintf(stderr, "%d %d\n", y, x);
        canvas->matrix[y][x] = rect.c;
        x++;
      }
      y++;
    }
  }
  else if (rect.mode == 'r')
  {
    while (y < (height + (int)rect.y) + 1)
    {
      x = (int)rect.x;
      while (x < (width + (int)rect.x))
      {
        if (y == (height + (int)rect.y) || y == (int)rect.y || x == (int)rect.x)
          canvas->matrix[y][x] = rect.c;
        x++;
      }
      if (x == (width + (int)rect.x) || y == (height + (int)rect.y))
          canvas->matrix[y][x] = rect.c;
      y++;
    }
  }
}

void  add_rect(t_canvas *canvas, FILE *file)
{
  t_rect rect;
  int scanf;

  scanf = fscanf(file, "%c %f %f %f %f %c\n", &rect.mode, &rect.x, &rect.y, &rect.width, &rect.height, &rect.c);
  while (scanf == 6)
  { 
    // fprintf(stderr, "%d %f %f\n", (int)rect.x, (int)rect.x - rect.x);
    // if ((int)rect.x - rect.x > 0.0000000)
    //   rect.x++;
    // if ((int)rect.y - rect.y > 0.0000000)
    //   rect.y++;
    // if ((int)rect.width - rect.width > 0.0000000)
    //   rect.width++;
    // if ((int)rect.height - rect.height > 0.0000000)
    //   rect.height++;
    write_matrix(canvas, rect);
    scanf = fscanf(file, "%c %f %f %f %f %c\n", &rect.mode, &rect.x, &rect.y, &rect.width, &rect.height, &rect.c);
  }
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
    if (!(add_canvas_vars(&canvas, file)))
        return (str_err("Error: Wrong data in file\n", 1));
    add_rect(&canvas, file);
    draw(canvas);
    ft_free(canvas);
    fclose(file);
    return (0);
}
