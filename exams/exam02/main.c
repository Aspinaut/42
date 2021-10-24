#include <stdio.h>
#include "ft_printf.c"

int main()
{
	printf("%d\n", printf("Bonjour %s %s %d %x\n", NULL, "...vincent...", 42, 42));
	printf("%d\n", ft_printf("Bonjour %s %s %d %x\n", NULL, "...vincent...", 42, 42));
	return (0);
}
