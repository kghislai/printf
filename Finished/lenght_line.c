/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:01:43 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 15:54:07 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
int ft_intlenhex(unsigned int i)
{
    int count;

    if (i == 0)
        return (1);
    count = 0;
    while (i != 0)
    {
        i /= 10;
        count++;
    }
    return (count);
}
int ft_intlen(int i)
{
    int count;

    if (i == 0)
        return (1);
    count = 0;
    while (i != 0)
    {
        i /= 10;
        count++;
    }
    return (count);
}
int ft_hexlen(unsigned long int i)
{
    int k;

    k = 1;
    while (i >= 16)
    {
        i /= 16;
        k++;
    }
    return (k);
}