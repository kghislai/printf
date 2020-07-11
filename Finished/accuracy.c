/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accuracy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:00:21 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/09 19:01:14 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_accuracy(char *search, int i)
{
    while (*search)
    {   
        if (*search == '.')
        {
            search++;
            if (i == 1)
                return (1);
            else
                return (ft_atoi(search));
        }
        search++;
    }
    return (0);
}
int ft_accuracy_zero(char *srch)
{
    int flag;
    int i;

    i = 0;
    flag = 0;
    while (srch[i] == '\t' || srch[i] == '\n' || srch[i] == '\v' ||
			srch[i] == '\f' || srch[i] == '\r' || srch[i] == ' ')
		i++;
    if (srch[i] == '-')
		return (0);
    while (srch[i] >= '0' && srch[i] <= '9')
		{
            if (srch[i] != '0')
                flag++;
            if (srch[i] == '0' && flag == 0 && !ft_accuracy(srch, 1) && srch[i + 1] != '-')
                return (1);
            i++;
        }
    return (0);
}
int ft_accuracy_point(char *search, int accuracy, int star)
{
    int flag;

    if (star == 4 && accuracy == 0)
        return (1);
    flag = 0;
    while (*search)
    {
        if (*search == '.')
        {
            search++;
            if (*search == '\0')
                return (1);
            while (*search == '0')
                search++;
            if (*search > '0' && *search <= '9')
                return (0);
        }
        if (*search == '\0')
            return (1);
        search++;
    }
    return (0);
}