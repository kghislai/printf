#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

int			ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
int ft_strlen_int(int i)
{
    int count;

    count = 0;
    while (i != 0)
    {
        i /= 10;
        count++;
    }
    return (count);
}
void ft_print_hex(unsigned long int i, char c)
{
    int j;
    char arr[16] = "0123456789abcdef";
    char arr1[16] = "0123456789ABCDEF";
    int *arrint;

    j = ft_strlen_int(i);
    arrint = malloc(sizeof(int) * j + 1);
    j = 0;
    while (i != 0)
    {
        arrint[j++] = i % 16;
        i /= 16;
    }
    while (j != 0)
    {
        if (c == 'x') 
            ft_putchar(arr[arrint[--j]]);
        if (c == 'X')
            ft_putchar(arr1[arrint[--j]]);
    } 
    free(arrint);
}
void ft_print_xX(unsigned long int i, char c)
{
    ft_print_hex(i, c);
}
int str_contains(char c)
{
    static char conversions[] = "cspdiuxX";
    int         i;

    i = 0;
    while (conversions[i])
    {
        if (c == conversions[i++])
            return (1);
    }
    return (0);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
int flags(char flag, char *search)
{
    while (*search)
    {
        if (*search == flag)
            return (1);
        search++;
    }
    return (0);
}

void    ft_print_d(char *f, int d_i)
{
    int i;
    int l_justfy;
    int force_pos;

    l_justfy = flags('-', f);
    force_pos = flags('+', f);
    i = atoi(f + (l_justfy + force_pos));
    if (l_justfy)
    {
        if (force_pos)
            ft_putchar('+');
        i = i - (ft_strlen_int(d_i) - 1);
        ft_putnbr(d_i);
        while (--i > 0)
            ft_putchar(' ');
    }
    else
    {
        i = i - (ft_strlen_int(d_i) - 1);
        while (--i > 0)
            ft_putchar(' ');
        if (force_pos)
            ft_putchar('+');
        ft_putnbr(d_i);
    }
}
void ft_print_p(unsigned long int i)
{
    ft_putstr("0x");
    ft_print_hex(i, 'x');
}
void ft_print_c(char c)
{
    ft_putchar(c);
}
void ft_print_s(char *s)
{
    ft_putstr(s);
}
void    my_printf(char *format, ...)
{
    char    *traverse;
    va_list arg;
    int     i;
    char    *flags; 

    va_start(arg, format);
    i = 0;
    flags = malloc(ft_strlen(format));
    traverse = format;
    while (*traverse)
    {
        if (*traverse == '%')
        {
            i = 0;
            traverse++;
            while (!str_contains(*traverse))
                flags[i++] = *traverse++;
            
            if (*traverse == 'd' || *traverse == 'i')
                ft_print_d(flags, va_arg(arg, int));
            if (*traverse == 'c')
                ft_print_c(va_arg(arg,int));
            if (*traverse == 's')
                ft_print_s(va_arg(arg,char *));
            if (*traverse == 'x')
                ft_print_xX(va_arg(arg, unsigned int), 'x');
            if (*traverse == 'X')
                ft_print_xX(va_arg(arg, unsigned int), 'X');
            if (*traverse == 'p')
                ft_print_p(va_arg(arg, unsigned long int));
        }
        else
            ft_putchar(*traverse);
        traverse++;
    }
    va_end(arg);
}

int     main(void)
{
    printf("|%9d|%c|%s|%x\n\n",1588,'q',"Hello", 57790);
    my_printf("|%9d|%c|%s|%x\n\n",1588,'q',"Hello", 57790);
    
    return (0);
}