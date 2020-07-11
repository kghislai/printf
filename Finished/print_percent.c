/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:55:30 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 19:24:24 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_perc(char *f, va_list arg)
{
    int i;
    int minus;
    int accuracy;

    if ((flags('*', f)))
        i = va_arg(arg,int);
    else
        i = ft_atoi(f);
    minus = flags('-', f);
    if (ft_accuracy_zero(f))
    {
        i = 0;
        accuracy = ft_atoi(f);
        while (--accuracy > 0)
            ft_putchar('0', 0);
    }
    if (i < 0)
    {
        minus = - 1;
        i *= - 1;
    }
    ft_print_lr(i, minus, '%');
}