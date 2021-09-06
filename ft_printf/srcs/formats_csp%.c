/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_csp%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:38:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/06 17:03:16 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_print_char(t_var *vartab)
{
    char c;

    c = va_arg(vartab->args, int);
    vartab->len += write(1, &c, 1);
}

void ft_print_str(t_var *vartab)
{
    char *s;

    s = va_arg(vartab->args, char *);
    if (!s)
      s  = "(null)";
    vartab->len += write(1, s, ft_strlen(s));
}

void ft_print_address(t_var *vartab)
{
  unsigned long p;

  p = (unsigned long)va_arg(vartab->args, void *);
  if (!p)
    vartab->len += write(1, "(nil)", 5);
  else
  {
    vartab->len += write(1, "0x", 2);
    ft_putnbr_hex_long(vartab, p, 'x');
  }
}

void ft_print_per(t_var *vartab)
{
    ft_putchar('%');
    vartab->len++;
}
