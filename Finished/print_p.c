/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:54:41 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 19:14:58 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_p_left(int acc_point, int i, char *f, unsigned long int p)
{
    ft_putstr("0x");
        if (!acc_point)
            ft_print_hex(p, 'x');
        i = ft_accuracy(f, 1) == 1 ? i + 1 : i + 0;
        while ((--i  - 1 - ft_hexlen(p)) > 0)
            ft_putchar(' ', 0);
}
void ft_print_p_right(int acc_point, int i, char *f, unsigned long int p)
{
    i = ft_accuracy(f, 1) == 1 ? i + 1 : i + 0;
        while ((--i - 1 - ft_hexlen(p)) > 0)
            ft_putchar(' ', 0);
        ft_putstr("0x");
        if (!acc_point)
            ft_print_hex(p, 'x');
}
void ft_print_p(char *f, unsigned long int p, va_list arg)
{
    int i;
    int minus;
    int acc_point;

    acc_point = ft_accuracy_point(f, 1, 1);
    if ((flags('*', f)))
        i = va_arg(arg, unsigned long int);
    else
        i = ft_atoi(f);
    minus = flags('-', f);
    if (i < 0)
    {
        minus = - 1;
        i *= - 1;
    }
    p = va_arg(arg, unsigned long int);
    if (minus)
        ft_print_p_left(acc_point, i, f, p);
    else
        ft_print_p_right(acc_point, i, f, p);
}