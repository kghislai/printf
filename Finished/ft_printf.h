#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void ft_print_left(int accuracy, long long int d_i, int i, int acc_point);
void ft_print_right(int accuracy, long long int d_i, int i, int acc_point);
void    ft_print_acczero(char *f, int *i, long long int d_i, int *accuracy);
int ft_print_stars(va_list arg, int *i, int *accuracy, char *f);
void ft_print_lr(int i, int minus, char c);
void        ft_print_d(char *f, long long int d_i, va_list arg);
void        ft_bzero(void *s, size_t n);
int         ft_putchar(char c, int end);
void        ft_putstr(char *s);
int         ft_atoi(const char *str);
int         ft_strlen(const char *s);
int         ft_intlenhex(unsigned int i);
int         ft_intlen(int i);
int         ft_hexlen(unsigned long int i);
void        ft_print_hex(unsigned long int i, char c);
int         ft_case(char c);
int         ft_accuracy_point(char *search, int accuracy, int star);
void        ft_putnbr(long long int n);
int         flags(char flag, char *search);
int         ft_accuracy(char *search, int i);
int         ft_stars(char *search);
int         ft_accuracy_zero(char *srch);
void        ft_print_p(char *f, unsigned long int p, va_list arg);
void        ft_print_xX(char *f, unsigned long int d_i, va_list arg, char c);
void        ft_print_c(char *f, char c, va_list arg);
void        ft_print_s(char *f, char* s, va_list arg);
void        ft_print_u(char *f, unsigned int d_i, va_list arg);
void        ft_print_perc(char *f, va_list arg);
int         ft_printf(const char *format, ...);

#endif
