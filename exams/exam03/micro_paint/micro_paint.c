#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define ZERO 0.00000000
#define ONE 1.00000000

typedef struct s_canvas
{
    int w;
    int h;
    char c;
    char *matrix;
}               t_canvas;

typedef struct s_rect
{
    char m;
    float x;
    float y;
    float w;
    float h;
    char c;
}               t_rect;

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

int str_err(char *err, FILE *file, int ret)
{
    write(1, err, ft_strlen(err));
    if (file)
        fclose(file);
    return (ret);
}

void print_canvas(t_canvas *canvas)
{
    int i = -1;

    while (++i < canvas->h)
    {
        write(1, canvas->matrix + i * canvas->w, canvas->w);
        write(1, "\n", 1);
    } 
}

int check_point(float x, float y, t_rect *r)
{
	if ((((x < r->x) || (r->x + r->w < x)) || y < r->y) || (r->y + r->h < y))
		return (0);
	if (((x - r->x < ONE) || ((r->x + r->w) - x < ONE)) ||
		((y - r->y < ONE || ((r->y + r->h) - y < ONE))))
		return (2); // Border
	return (1);	
}

void write_matrix(t_canvas *canvas, t_rect *rect)
{
    int i;
    int j;
    int point;

    i = -1;
    while (++i < canvas->w)
    {
        j = -1;
        while (++j < canvas->h)
        {
            point = check_point((float)i, (float)j, rect);
            if (point == 2 || (point == 1 && rect->m == 'R'))        
                canvas->matrix[i + j * canvas->w] = rect->c;
        }
    }
}

int draw_canvas(FILE *file, t_canvas *canvas)
{
    int i = -1;

    if (fscanf(file, "%d %d %c\n", &canvas->w, &canvas->h, &canvas->c) != 3)
        return (str_err("Error: Operation file corrupted\n", file, 1));
    if (canvas->w <= 0 || canvas->w > 300 || canvas->h <= 0 || canvas->h > 300)
        return (str_err("Error: Operation file corrupted\n", file, 1));
    canvas->matrix = malloc(sizeof(char) * (canvas->h * canvas->w + 1));
    if (!canvas->matrix)
        return (str_err("Error: Operation file corrupted\n", file, 1));
    while (++i < canvas->h * canvas->w)
    {
        canvas->matrix[i] = canvas->c;
    }
    canvas->matrix[i] = '\0';
    return (0);
}

int draw_rect(FILE *file, t_canvas *canvas, t_rect *rect)
{
    int scan;

    scan = fscanf(file, "%c %f %f %f %f %c\n", &rect->m, &rect->x, &rect->y, &rect->w, &rect->h, &rect->c);
    while (scan == 6)
    {
        if ((rect->m != 'r' && rect->m != 'R') || rect->w <= ZERO || rect->h <= ZERO)
            return (str_err("Error: Operation file corrupted\n", file, 1));
        write_matrix(canvas, rect);
        scan = fscanf(file, "%c %f %f %f %f %c\n", &rect->m, &rect->x, &rect->y, &rect->w, &rect->h, &rect->c);
    }
    if (scan != -1)
        return (str_err("Error: Operation file corrupted\n", file, 1));
    return (0);
}

int draw(FILE *file, t_canvas *canvas, t_rect *rect)
{
    if (draw_canvas(file, canvas))
        return (1);
    if (draw_rect(file, canvas, rect))
        return (1);
    print_canvas(canvas);
    return (0);
}

int main(int argc, char **argv)
{
    FILE        *file;
    t_canvas    canvas;
    t_rect      rect;

    canvas.w = 7;
    if (argc != 2)
        return (str_err("Error: argument\n", file, 1));
    file = fopen(argv[1], "r");
    if (!file)
        return (str_err("Error: Operation file corrupted\n", file, 1));
    return (draw(file, &canvas, &rect));
}