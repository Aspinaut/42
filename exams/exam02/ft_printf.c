#include <unistd.h>
#include <stdarg.h>

typedef struct s_arg
{
	int len;
}	t_arg;

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int i = 0;

	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void ft_putnbr(int nb, t_arg *arg)
{
	if (nb < 0)
	{
		nb = nb * -1;
		arg->len += ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, arg);
		arg->len += ft_putchar(nb % 10 + '0');
	}
	else
	{
		arg->len += ft_putchar(nb + '0');
	}
}

void ft_putnbr_hex(unsigned int nb, t_arg *arg, int converter)
{
	if (nb < 0)
	{
		nb = nb * -1;
		arg->len += ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, arg);
		arg->len += ft_putchar(nb % 10 + '0');
	}
	else
	{
		arg->len += ft_putchar(nb + '0');
	}
}

int ft_printf(char const *format, ...)
{
	t_arg arg;
	int pos = -1;
	va_list args;

	va_start(args, format);
	arg.len = 0;
	while (format[++pos])
	{
		if (format[pos] == '%' && format[pos + 1] == 's')
		{
			if (!(arg.len += ft_putstr(va_arg(args, char *))))
			{
				arg.len += ft_putstr("(null)");
			}
		}
		else if (format[pos] == '%' && format[pos + 1] == 'd')
		{
			ft_putnbr(va_arg(args, int), &arg);
		}
		else if (format[pos] == '%' && format[pos + 1] == 'x')
		{
			ft_putnbr_hex(va_arg(args, unsigned int), &arg, 'x');
		}
		else
		{
			arg.len += ft_putchar(format[pos]);
		}
	}
	va_end(args);
	return(arg.len);
}
