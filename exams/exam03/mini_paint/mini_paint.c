#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define ZERO 0.00000000
#define ONE 1.00000000

typedef struct s_canvas
{
	int w;
	int h;
	char c;
	char *matrix;
}	t_canvas;

typedef struct s_circle
{
	float x;
	float y;
	float r;
	char c;
	char m;
}	t_circle;

int ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

int str_err(char *err, FILE *f, int file)
{
    write(1, err, ft_strlen(err));
    if (file)
        fclose(f);
    return (1);
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

int check_point(float x, float y, t_circle *circle)
{
	float dist;

	dist = sqrtf(powf(x - circle->x, 2.) + powf(y - circle->y, 2.));
	if (dist <= circle->r)
	{
		if (circle->r - dist < ONE)
			return (2);
		return (1);
	}
	return (0);
}

void write_matrix(t_canvas *canvas, t_circle *circle)
{
	int i = -1;
	int j;
	int point;

	while (++i < canvas->w)
	{
		j = -1;
		while (++j < canvas->h)
		{
			point = check_point((float)i, (float)j, circle);
			if (point == 2 || (point == 1 && circle->m == 'C'))
				canvas->matrix[i + j * canvas->w] = circle->c;
		}
	}
}

int draw_circle(FILE *file, t_canvas *canvas, t_circle *circle)
{
	int scan;

	scan = fscanf(file, "%c %f %f %f %c\n", &circle->m, &circle->x, &circle->y, &circle->r, &circle->c);
	while (scan == 5)
	{
		if ((circle->m != 'c' && circle->m != 'C') || circle->r <= ZERO)
			return (str_err("Error File corrupted\n", file, 1));
		write_matrix(canvas, circle);
		scan = fscanf(file, "%c %f %f %f %c\n", &circle->m, &circle->x, &circle->y, &circle->r, &circle->c);
	}
	if (scan != -1)
		return (str_err("Error File corrupted\n", file, 1));
	return (0);
}

int draw_canvas(FILE *file, t_canvas *canvas)
{
	int i = -1;

	if (fscanf(file, "%d %d %c\n", &canvas->w, &canvas->h, &canvas->c) != 3)
		return (str_err("Error File corrupted\n", file, 1));
	canvas->matrix = malloc(sizeof(char) * (canvas->w * canvas->h + 1));
	if (!canvas->matrix)
		return (str_err("Error malloc failed\n", file, 1));
	while (++i < canvas->h * canvas->w)
		canvas->matrix[i] = canvas->c;
	canvas->matrix[i] = '\0';
	return (0);
}

int draw(FILE *file, t_canvas *canvas, t_circle *circle)
{
	if (draw_canvas(file, canvas))
		return (str_err("Error File corrupted\n", file, 1));
	if (draw_circle(file, canvas, circle))
		return (str_err("Error File corrupted\n", file, 1));
	print_canvas(canvas);
	free(canvas->matrix);
	fclose(file);
	return (0);
}

int main(int argc, char **argv)
{
	FILE *file;
	t_canvas canvas;
	t_circle circle;

	if (argc != 2)
		return (str_err("Error Args\n", file, 1));
	file = fopen(argv[1], "r");
	if (!file)
		return (str_err("Error File corrupted\n", file, 1));
	return (draw(file, &canvas, &circle));

}
