/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:36:22 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 19:16:49 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_left(int accuracy, long long int d_i, int i, int acc_point)
{
    if (accuracy)
        {
            if (accuracy > (ft_intlen(d_i)))
                accuracy = accuracy - ft_intlen(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_intlen(d_i) - 1) - accuracy;
        if(d_i < 0)
        {
            i--;
            ft_putchar('-', 0);
            d_i *= -1;
        }
        while (accuracy-- >0)
            ft_putchar('0', 0);
        if (!acc_point)
            ft_putnbr(d_i);
        while (--i + acc_point  > 0)
            ft_putchar(' ', 0);
}
void ft_print_right(int accuracy, long long int d_i, int i, int acc_point)
{
    if (accuracy)
        {
            if (accuracy > (ft_intlen(d_i)))
                accuracy = accuracy - ft_intlen(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_intlen(d_i) - 1) - accuracy;
        if(d_i < 0)
        {
            i--;
            while (--i > 0)
                ft_putchar(' ', 0);
            ft_putchar('-', 0);
            d_i *= -1;
        }
        while (--i + acc_point > 0)
            ft_putchar(' ', 0);
        while (accuracy-- >0)
            ft_putchar('0', 0); 
        if (!acc_point)
            ft_putnbr(d_i);
}
void    ft_print_acczero(char *f, int *i, long long int d_i, int *accuracy)
{
    if (ft_accuracy_zero(f))
    {
        int star;

        star = ft_stars(f);
        *i = 0;
        if (star < 2)
            *accuracy = d_i < 0 ? (ft_atoi(f) - 1): ft_atoi(f);
        if (star == 4 && d_i < 0)
            *i = *accuracy;
        if ((star >= 2 && star <= 4) && d_i < 0)
            *accuracy -= 1;
    }
}
int ft_print_stars(va_list arg, int *i, int *accuracy, char *f)
{
    int star;
    
    star = ft_stars(f);
    
    if (star == 1 || star == 2 || star == 5)
        *i = va_arg(arg, int);    
    if (star == 2 || star == 3 || star == 4)
        *accuracy = va_arg(arg, int);
    return (star);
}
void    ft_print_d(char *f, long long int d_i, va_list arg)
{
    int i;
    int minus;
    int accuracy;
    int star;
    int acc_point;

    accuracy = ft_accuracy(f, 0);
    minus = flags('-', f);
    i = ft_atoi(f + (minus));
    star = ft_print_stars(arg, &i, &accuracy, f);
    d_i = va_arg(arg, int);
    acc_point = ft_accuracy_point(f, accuracy, star);
    ft_print_acczero(f, &i, d_i, &accuracy);
    if (i < 0)
    {
        i *= - 1;
        minus = 1;
    }
    if (minus)
        ft_print_left(accuracy, d_i, i, acc_point);
    else
        ft_print_right(accuracy, d_i, i, acc_point);
}