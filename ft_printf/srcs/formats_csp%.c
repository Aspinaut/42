/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats_csp%.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:38:12 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/17 13:58:35 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_print_char(t_var *vartab)
{
    char c;

    c = va_arg(vartab->args, int);
    vartab->len_to_print += write(1, &vartab->args, 1);
}