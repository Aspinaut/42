/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:05:13 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/17 13:21:43 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_var *ft_init_vartab(t_var *vartab)
{
  vartab->args = 0;
  vartab->len_to_print = 0;
  return (vartab);
}

static int ft_process_specifier(t_var *vartab, const char *f, int pos)
{

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

  while (f[pos] != 'c' || f[pos] != 's' || f[pos] != 'p' ||\ 
        f[pos] != 'd' || f[pos] != 'i' || f[pos] != 'u' ||\
        f[pos] != 'x' || f[pos] != 'X' || f[pos] != '%')
  {
    
    pos++;
  }
  pos = ft_process_specifier(vartab, f, pos);
  return (pos);
}

int ft_printf(const char *format, ...)
{
  va_list args;
  t_var *vartab;
  int len_to_print;
  int pos;

  vartab = (t_var *)malloc(sizeof(t_var));
  if (!vartab)
    return (-1);
  vartab = ft_init_vartab(vartab);
  va_start(args, format);
  len_to_print = 0;
  pos = -1;
  while (format[++pos])
  {
    if (format[pos] == '%')
      pos = ft_eval_format(vartab, format, pos + 1);

    // gerer l'erreur si % est a la fin de format ? 

    else
      len_to_print += write(0, &format[pos], 1);
  }
  va_end(args);
  len_to_print += vartab->len_to_print;
  free(vartab);
  return (len_to_print);
}

int main()
{
  // char *s = "salut";
  // int i = 0;
  
  // ft_printf("FT_PRINTF : salut %%\n");
  printf("PRINTF : %\n", "salut");
  printf("PRINTF : %c\n", 'a');
  return (0);
}