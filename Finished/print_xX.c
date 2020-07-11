/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:59:21 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/09 18:59:43 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_xX(char *f, unsigned long int d_i, va_list arg, char c)
{
    int i;
    int minus;
    int accuracy;
    int star;
    int acc_point;

    star = ft_stars(f);
    accuracy = ft_accuracy(f, 0);
    minus = flags('-', f);
    i = ft_atoi(f + (minus));
    
    if (star == 1 || star == 2 || star == 5)
        i = va_arg(arg, int);    
    if (star == 2 || star == 3 || star == 4)
        accuracy = va_arg(arg, int);
    d_i = va_arg(arg, unsigned int);
    acc_point = ft_accuracy_point(f, accuracy, star);
    if (ft_accuracy_zero(f))
    {
        i = 0;
        if (star < 2)
            accuracy = d_i < 0 ? (ft_atoi(f) - 1): ft_atoi(f);
        if (star == 4 && d_i < 0)
            i = accuracy;
        if ((star >= 2 && star <= 4) && d_i < 0)
            accuracy -= 1;
            
    }
    if (i < 0)
    {
        i *= - 1;
        minus = 1;
    }
    if (minus)
    {
        if (accuracy)
        {
            if (accuracy > (ft_hexlen(d_i)))
                accuracy = accuracy - ft_hexlen(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_hexlen(d_i) - 1) - accuracy;
        while (accuracy-- >0)
            ft_putchar('0', 0);
        if (!acc_point)
            ft_print_hex(d_i, c);
        while (--i + acc_point > 0)
            ft_putchar(' ', 0);
    }
    else
    {
        if (accuracy)
        {
            if (accuracy > (ft_hexlen(d_i)))
                accuracy = accuracy - ft_hexlen(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_hexlen(d_i) - 1) - accuracy;
        while (--i + acc_point > 0)
            ft_putchar(' ', 0);
        while (accuracy-- >0)
            ft_putchar('0', 0); 
        if (!acc_point)
            ft_print_hex(d_i, c);
    }
}