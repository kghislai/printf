/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:58:44 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 19:17:27 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_print_u(char *f, unsigned int d_i, va_list arg)
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
    d_i = va_arg(arg, unsigned int);
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
