/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:53:20 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 19:25:30 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_lr(int i, int minus, char c)
{
    if (minus)
    {
        ft_putchar(c, 0);
        while (--i > 0)
            ft_putchar(' ', 0);
    }
    else
    {
        while (--i > 0)
            ft_putchar(' ', 0);
        ft_putchar(c, 0);
    }
}
void ft_print_c(char *f, char c, va_list arg)
{
    int i;
    int minus;
    
    if ((flags('*', f)))
        i = va_arg(arg,int);
    else
        i = ft_atoi(f);
    minus = flags('-', f);
    if (i < 0)
    {
        minus = - 1;
        i *= - 1;
    }
    c = va_arg(arg,int);
    ft_print_lr(i, minus, c);
}