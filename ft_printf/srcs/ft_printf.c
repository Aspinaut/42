/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:05:13 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/18 12:52:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void ft_init_vartab(t_var *vartab)
{
  vartab->len_to_print = 0;
}

static void ft_process_specifier(t_var *vartab, const char *format, int pos)
{
  if (format[pos] == 'c')
    ft_print_char(vartab);
  if (format[pos] == 's')
    ft_print_str(vartab);
  if (format[pos] == 'p')
    ft_print_address(vartab);
  if (format[pos] == '%')
    ft_print_per(vartab);
  if (format[pos] == 'd' || format[pos] == 'i')
    ft_print_int(vartab);
  // if ()
  //   ft_print_char(vartab);
  // if (format[pos] == 'u')
  //   ft_print_char(vartab);
  // if (format[pos] == 'x')
  //   ft_print_char(vartab);
  // if (format[pos] == 'X')
  //   ft_print_char(vartab);
  // printf("SPE : %d\n", ++pos);
}
static int ft_eval_format(t_var *vartab, const char *f, int pos)
{
  // format specifier : cspdiuxX%
  // precision / padding : -0.
  // flags : # +

  /*
    - tant qu'on a autre chose qu'un format specifier ( == tant qu'on peut impacter celui ci)
      - on gere chaque cas de flags / precision
    - si on quitte cette boucle, on sait qu'on est arrive au specifier et on peut print
  */

  while (f[pos] && (f[pos] != 'c' && f[pos] != 's' && f[pos] != 'p' && \
        f[pos] != 'd' && f[pos] != 'i' && f[pos] != 'u' && \
        f[pos] != 'x' && f[pos] != 'X' && f[pos] != '%'))
  {
    // printf("CHAR : %c\n", f[pos]);
    pos++;
  }
  ft_process_specifier(vartab, f, pos);
  return (pos);
}

int ft_printf(const char *format, ...)
{
  t_var   *vartab;
  int     len_to_print;
  int     pos;

  vartab = (t_var *)malloc(sizeof(t_var));
  if (!vartab)
    return (-1);
  ft_init_vartab(vartab);
  va_start(vartab->args, format);
  len_to_print = 0;
  pos = -1;
  while (format[++pos])
  {
    if (format[pos] == '%')
      pos = ft_eval_format(vartab, format, pos + 1);
    else
      len_to_print += write(1, &format[pos], 1);
  }
  va_end(vartab->args);
  len_to_print += vartab->len_to_print;
  free(vartab);
  return (len_to_print);
}

int main()
{
  char *s = "salut";
  int i = 8749981;
  char c = 'a';
  void *p = &s;

  printf("----------------------\n");
  printf("-------FT_PRINTF------\n");
  printf("----------------------\n");
  // ft_printf("| %% %p coucou\n", p);
  printf("%d", ft_printf("| %i coucou\n", i));
  // printf("%d\n", ft_printf("| %s coucou\n", s));
  printf("----------------------\n");
  printf("-------PRINTF---------\n");
  printf("----------------------\n");
  printf("%d", printf("| %i coucou\n", i));
  // printf("%d\n", printf("| %s coucou\n", s));

  return (0);
}
