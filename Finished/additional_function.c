/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:12:46 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 17:45:49 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = 0;
		i++;
	}
}
int ft_helpstars(char *search, int i, char *flags)
{
    if ((ft_accuracy(flags, 1)) && *search == '*')
        {
            search++;
            if(*search == '.')
            {
                search++;
                if (*search == '*')
                    return (2); // две * на точности и ширине
                if ((*search >= '0' && *search <= '9'))
                    return (5);
            }
            return (3); // одна *  на точности (ширина есть)
        }
        if (!i)
        {
            if(*search == '.' || *search == '0')
            {
                search++;
                if (*search == '*')
                    return (4); // одна * на точности (ширины нет)
            }
        }
    return (0);
}

int ft_stars(char *search)
{
    int i;
    char *flags;
    flags = search;

    i = ft_atoi(search);
    while (*search)
    {
        if (ft_helpstars(search, i,flags))
            return(ft_helpstars(search, i, flags));
        if (!ft_accuracy(flags, 1) && *search == '*')
            return (1); // одна * на ширине (точности нет)
        search++;
    }
    return (0); // нет звезд
}