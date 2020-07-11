#include "ft_printf.h"

int  ft_case(const char c)
{
     char conversions[] = "cspdiuxX%";
    int         i;

    i = 0;
    while (conversions[i])
    {
        if (c == conversions[i++])
            return (1);
    }
    return (0);
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
void ft_output(const char *traverse, va_list arg, char *flags)
{         
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
void ft_cycle(const char *traverse, char *flags, va_list arg, const char *format)
{
    int i;

    i = 0;
    while (*traverse)
    {
        if (*traverse == '%')
        {
            traverse++;
            i = 0;
            while (!ft_case(*traverse))
                flags[i++] = *traverse++;
            ft_output(traverse, arg, flags);
        }
        else
            ft_putchar(*traverse, 0);
        traverse++;
        ft_bzero(flags, ft_strlen(format));
    }
}
int   ft_printf(const char *format, ...)
{
    const char    *traverse;
    va_list arg;
    char    *flags; 
    va_start(arg, format);
    flags = malloc(ft_strlen(format));
    if (flags == NULL)
        return (0);
    traverse = format;
    ft_cycle(traverse, flags, arg, format);
    va_end(arg);
    free(flags);
    return (ft_putchar('e', 1));
}
