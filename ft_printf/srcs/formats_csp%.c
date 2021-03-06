/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_csp%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:38:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/18 12:18:04 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_print_char(t_var *vartab)
{
    char c;

    c = va_arg(vartab->args, int);
    vartab->len_to_print += write(1, &c, 1);
}

void ft_print_str(t_var *vartab)
{
    char *s;

    s = va_arg(vartab->args, char *);
    vartab->len_to_print += write(1, s, ft_strlen(s));
}

void ft_print_address(t_var *vartab)
{
    // char *s;
    void *p;

    p = va_arg(vartab->args, char *);
    // p = &s;
    // printf("ADD : %p\n", p);
  vartab->len_to_print += write(1, p, ft_strlen(p));
}

void ft_print_per(t_var *vartab)
{
    ft_putchar('%');
    vartab->len_to_print++;
}
