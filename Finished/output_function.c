/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghislai <kghislai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:05:37 by kghislai          #+#    #+#             */
/*   Updated: 2020/07/11 18:19:19 by kghislai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int end)
{
    static int count = 0;
    int i;

    if (end)
    {
        i = count;
        count = 0;
        return (i);
    }
        
	write(1, &c, 1);
    count++;
    return (0);
}
void	ft_putstr(char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i], 0);
			i++;
		}
	}
}
void ft_print_hex(unsigned long int i, char c)
{
    int j;
    char arr[16] = "0123456789abcdef";
    char arr1[16] = "0123456789ABCDEF";
    int *arrint;

    j = ft_intlenhex(i);
    arrint = malloc(sizeof(int) * j + 1);
    j = 0;
    if (i == 0)
        ft_putchar('0', 0);
    while (i != 0)
    {
        arrint[j++] = i % 16;
        i /= 16;
    }
    while (j != 0)
    {
        if (c == 'x') 
            ft_putchar(arr[arrint[--j]], 0);
        if (c == 'X')
            ft_putchar(arr1[arrint[--j]], 0);
    } 
    free(arrint);
}
void	ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-', 0);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0', 0);
	}
	else
		ft_putchar(n + '0', 0);
}