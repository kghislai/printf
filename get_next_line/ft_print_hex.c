#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
void ft_print_hex(int i, char c)
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
int main()
{
    ft_print_hex(57790, 'X');
    return (0);
}