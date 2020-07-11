/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:57:34 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/09 18:57:58 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_s(char *f, char* s, va_list arg)
{
    int i;
    int minus;
    int accuracy;
    int star;
    int acc_point;

    star = ft_stars(f);
    accuracy = ft_accuracy(f, 0);
    minus = flags('-', f);
    i = ft_atoi(f);
    
    if (star == 1 || star == 2 || star == 5)
        i = va_arg(arg, int);    
    if (star == 2 || star == 3 || star == 4)
        accuracy = va_arg(arg, int);
    acc_point = ft_accuracy_point(f, accuracy, star);
    s = va_arg(arg, char *);
    if(accuracy < 0 || (accuracy < 0 && (star > 1 && star < 5)))
        accuracy = 0;
    if (s == NULL)
        s = "(null)";
    if (i < 0)
    {
        i *= - 1;
        minus = 1;
    }
    if (minus)
    {
        if (accuracy && !acc_point)
        {
            if (accuracy >= (ft_strlen(s)))
               {
                   i = i - ft_strlen(s);
                   accuracy = ft_strlen(s);
               } 
            else
                i = i - accuracy;
            while (*s != '\0' && accuracy-- > 0 && !acc_point)
		        ft_putchar(*s++, 0);    
        }
        if (!accuracy && !acc_point)
        {
            i = i - ft_strlen(s);
            while (*s != '\0' && !acc_point)
		        ft_putchar(*s++, 0);
        }
        while (--i >= 0)
            ft_putchar(' ', 0);
    }
    else
    {
        if (accuracy)
        {
            if (accuracy >= (ft_strlen(s)))
                accuracy = ft_strlen(s);
            i = i - accuracy;
        }
        if (!accuracy && !acc_point)
            i = i - ft_strlen(s);
        while ((--i) >= 0)
            ft_putchar(' ', 0);
        if (accuracy)
        {
        while (*s != '\0' && accuracy-- > 0 && !acc_point)
		    ft_putchar(*s++, 0);
        }
        else
        {
            while (*s != '\0' && !acc_point)
		        ft_putchar(*s++, 0);
        }
    }
}