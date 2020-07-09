#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
int ft_atoi(const char *str)
{
	int	i;
	int	is_neg;
	int	res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	is_neg = (str[i] == '-') ? -1 : 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * is_neg);
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
void ft_print_hex(unsigned long int i, char c)
{
    int j;
    char arr[16] = "0123456789abcdef";
    char arr1[16] = "0123456789ABCDEF";
    int *arrint;

    j = ft_strlen_int(i);
    arrint = malloc(sizeof(int) * j + 1);
    j = 0;
    if (i == 0)
        ft_putchar('0');
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
int str_contains(char c)
{
    static char conversions[] = "cspdiuxX%";
    int         i;

    i = 0;
    while (conversions[i])
    {
        if (c == conversions[i++])
            return (1);
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
void	ft_putnbr(long long int n)
{
	if (n < 0)
	{
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
int ft_stars(char *search)
{
    int i;

    i = ft_atoi(search);
    while (*search)
    {
        if ((ft_accuracy(search, 1)) && *search == '*')
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
        if (!ft_accuracy(search, 1) && *search == '*')
            return (1); // одна * на ширине (точности нет)
        search++;
    }
    return (0); // нет звезд
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
void    ft_print_d(char *f, long long int d_i, va_list arg)
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
    d_i = va_arg(arg, int);
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
            if (accuracy > (ft_strlen_int(d_i)))
                accuracy = accuracy - ft_strlen_int(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_strlen_int(d_i) - 1) - accuracy;
        if(d_i < 0)
        {
            i--;
            ft_putchar('-');
            d_i *= -1;
        }
        while (accuracy-- >0)
            ft_putchar('0');
        if (!acc_point)
            ft_putnbr(d_i);
        while (--i + acc_point  > 0)
            ft_putchar(' ');
    }
    else
    {
        if (accuracy)
        {
            if (accuracy > (ft_strlen_int(d_i)))
                accuracy = accuracy - ft_strlen_int(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_strlen_int(d_i) - 1) - accuracy;
        if(d_i < 0)
        {
            i--;
            while (--i > 0)
                ft_putchar(' ');
            ft_putchar('-');
            d_i *= -1;
        }
        while (--i + acc_point > 0)
            ft_putchar(' ');
        while (accuracy-- >0)
            ft_putchar('0'); 
        if (!acc_point)
            ft_putnbr(d_i);
    }
}
void ft_print_p(char *f, unsigned long int p, va_list arg)
{
    int i;
    int minus;
    if ((flags('*', f)))
        i = va_arg(arg, unsigned long int);
    else
        i = ft_atoi(f);
    minus = flags('-', f);
    if (i < 0)
    {
        minus = - 1;
        i *= - 1;
    }
    p = va_arg(arg, unsigned long int);
    if (minus)
    {
        ft_putstr("0x");
        ft_print_hex(p, 'x');
        while ((--i - 1 - ft_hexlen(p)) > 0)
            ft_putchar(' ');
    }
    else
    {
        while ((--i - 1 - ft_hexlen(p)) > 0)
            ft_putchar(' ');
        ft_putstr("0x");
        ft_print_hex(p, 'x');
    }
}

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
    d_i = va_arg(arg, unsigned long int);
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
            ft_putchar('0');
        if (!acc_point)
            ft_print_hex(d_i, c);
        while (--i + acc_point > 0)
            ft_putchar(' ');
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
            ft_putchar(' ');
        while (accuracy-- >0)
            ft_putchar('0'); 
        if (!acc_point)
            ft_print_hex(d_i, c);
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
    if (minus)
    {
        ft_putchar(c);
        while (--i > 0)
            ft_putchar(' ');
    }
    else
    {
        while (--i > 0)
            ft_putchar(' ');
        ft_putchar(c);
    }
}

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
		        ft_putchar(*s++);    
        }
        if (!accuracy && !acc_point)
        {
            i = i - ft_strlen(s);
            while (*s != '\0' && !acc_point)
		        ft_putchar(*s++);
        }
        while (--i >= 0)
            ft_putchar(' ');
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
            ft_putchar(' ');
        if (accuracy)
        {
        while (*s != '\0' && accuracy-- > 0 && !acc_point)
		    ft_putchar(*s++);
        }
        else
        {
            while (*s != '\0' && !acc_point)
		        ft_putchar(*s++);
        }
    }
}

void ft_print_u(char *f, unsigned int d_i, va_list arg)
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
            if (accuracy > (ft_strlen_int(d_i)))
                accuracy = accuracy - ft_strlen_int(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_strlen_int(d_i) - 1) - accuracy;
        if(d_i < 0)
        {
            i--;
            ft_putchar('-');
            d_i *= -1;
        }
        while (accuracy-- >0)
            ft_putchar('0');
        if (!acc_point)
            ft_putnbr(d_i);
        while (--i + acc_point  > 0)
            ft_putchar(' ');
    }
    else
    {
        if (accuracy)
        {
            if (accuracy > (ft_strlen_int(d_i)))
                accuracy = accuracy - ft_strlen_int(d_i);
            else
                accuracy = 0;
        }
        i = i - (ft_strlen_int(d_i) - 1) - accuracy;
        if(d_i < 0)
        {
            i--;
            while (--i > 0)
                ft_putchar(' ');
            ft_putchar('-');
            d_i *= -1;
        }
        while (--i + acc_point > 0)
            ft_putchar(' ');
        while (accuracy-- >0)
            ft_putchar('0'); 
        if (!acc_point)
            ft_putnbr(d_i);
    }
}

void ft_print_perc(char *f, va_list arg)
{
    int i;
    int minus;
    int accuracy;

    if ((flags('*', f)))
        i = va_arg(arg,int);
    else
        i = ft_atoi(f);
    minus = flags('-', f);
    if (ft_accuracy_zero(f))
    {
        i = 0;
        accuracy = ft_atoi(f);
        while (--accuracy > 0)
            ft_putchar('0');
    }
    if (i < 0)
    {
        minus = - 1;
        i *= - 1;
    }
    if (minus)
    {
        ft_putchar('%');
        while (--i > 0)
            ft_putchar(' ');
    }
    else
    {
        while (--i > 0)
            ft_putchar(' ');
        ft_putchar('%');
    }
}
int   ft_printf(char *format, ...)
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
                ft_print_d(flags, 0, arg);
            if (*traverse == 'c')
                ft_print_c(flags,'c', arg);
            if (*traverse == 's')
                ft_print_s(flags,"", arg);
            if (*traverse == 'x')
                ft_print_xX(flags, 0, arg, 'x');
            if (*traverse == 'X')
                ft_print_xX(flags, 0, arg, 'X');
            if (*traverse == 'p')
                ft_print_p(flags, 0, arg);
            if (*traverse == '%')
                ft_print_perc(flags, arg);
            if (*traverse == 'u')
                ft_print_u(flags, 0, arg);
        }
        else
            ft_putchar(*traverse);
        traverse++;
        ft_bzero(flags, ft_strlen(format));
    }
    va_end(arg);
    free(flags);
    return (0);
}
