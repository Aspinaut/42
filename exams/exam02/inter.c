#include <unistd.h>

int is_used(char *ret, char c)
{
	int i;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == c)
		       return (1);	
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char ret[1000] = {};

	
	if (argc == 3)
	{
		i = 0;
		k = 0;
		while (argv[1][i])
		{	
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && !is_used(ret, argv[1][i]))
				{
					ret[k] = argv[1][i];
					write(1, &ret[k++], 1);
					break ;
				}
				j++;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}


