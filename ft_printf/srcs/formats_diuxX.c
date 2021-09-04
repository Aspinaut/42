/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_diuxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:35:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/04 09:13:59 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_print_int(t_var *vartab)
{
    int nb;

    nb = va_arg(vartab->args, int);
    ft_putnbr(vartab, nb);
}

void ft_print_unsigned_int(t_var *vartab)
{
    unsigned int nb;

    nb = va_arg(vartab->args, unsigned int);
    ft_putnbr_unsigned(vartab, nb);
}

void ft_print_hex_min(t_var *vartab)
{
  unsigned int nb;

  nb = va_arg(vartab->args, unsigned int);
  ft_putnbr_hex(vartab, nb, 'x');
}

void ft_print_hex_maj(t_var *vartab)
{
  unsigned int nb;

  nb = va_arg(vartab->args, unsigned int);
  ft_putnbr_hex(vartab, nb, 'X');
}
