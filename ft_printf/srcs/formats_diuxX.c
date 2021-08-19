/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_diuxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:38:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/19 18:22:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_print_int(t_var *vartab)
{
    int nb;

    nb = va_arg(vartab->args, int);
    vartab->len_to_print += ft_putnbr(nb);
}

void ft_print_unsigned_int(t_var *vartab)
{
    unsigned int nb;

    nb = va_arg(vartab->args, unsigned int);
    vartab->len_to_print += ft_putnbr_unsigned(nb);
}

void ft_print_hex_min(t_var *vartab)
{
    
}

void ft_print_hex_maj(t_var *vartab)
{
    
}