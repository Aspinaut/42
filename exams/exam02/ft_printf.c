#include <unistd.h>
#include <stdarg.h>

typedef struct s_arg
{
	int len;
}	t_arg;

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

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

void	ft_putnbr(int n, t_arg *arg)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		arg->len += ft_putchar('-');
	}
	if (nbr >= 0 && nbr < 10)
	{
		arg->len += ft_putchar(nbr + '0');
	}
	else
	{
		ft_putnbr(nbr / 10, arg);
		arg->len += ft_putchar(nbr % 10 + '0');
	}
}

void ft_putnbr_hex(unsigned int nb, t_arg *arg, unsigned int converter)
{
	unsigned int remainder = 0;
	unsigned int nb_cpy = nb;

	if (nb > 15)
	{
		nb = nb / 16;
		remainder = nb_cpy - (nb * 16);
		if (remainder < 10)
		{
			ft_putnbr_hex(nb, arg, converter);
			arg->len += ft_putchar(remainder + '0'); 
		}
		else
		{
			ft_putnbr_hex(nb, arg, converter);
			arg->len += ft_putchar(remainder + converter - 33); 
		}
	}
	else if (nb > 9 && nb < 16)
	{
		arg->len += ft_putchar(nb + converter - 33); 
	}
	else 
	{
		arg->len += ft_putchar(nb + '0'); 
	}
}

int ft_printf(const char *format, ...)
{
	t_arg arg;
	int i = -1;
	va_list args;
	char *s;

	va_start(args, format);
	arg.len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 's')		
			{
				s = va_arg(args, char *);
				if (!s)
					arg.len += ft_putstr("(null)");
				else
					arg.len += ft_putstr(s);
			}
			else if (format[i + 1] == 'd')		
			{
				ft_putnbr(va_arg(args, int), &arg);
			}
			else if (format[i + 1] == 'x')		
			{
				ft_putnbr_hex(va_arg(args, unsigned int), &arg, 'x');
			}
			i++;
		}
		else		
		{
			arg.len += write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (arg.len);
}