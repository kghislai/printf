#include <stdio.h> 
#include <stdarg.h>	
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
int ft_printf(const char *str, ...)
{
   const char *traverse; 
	unsigned int i; 
	char *s; 
	
	va_list arg; 
	va_start(arg, str); 
	traverse = str;
    while(*traverse != '\0')
    {
        if(*traverse != '%')
            ft_putchar(*traverse);
        if (*traverse == '%')
            traverse++;
        if (*traverse == 'c' )
        {
            i = va_arg(arg,int);
			putchar(i);
            break;
        }
        if(*traverse == 's')
        {
            s = va_arg(arg,char *);
			ft_putstr(s); 
			break;
        }
        
   
        

        traverse++;
    }





	for(traverse = str; *traverse != '\0'; traverse++) 
	{ 
		while( *traverse != '%' ) 
		{ 
			putchar(*traverse);
			traverse++; 
		} 
		
		traverse++; 
		
		//Module 2: Fetching and executing arguments
		switch(*traverse) 
		{ 
			case 'c' : i = va_arg(arg,int);		//Fetch char argument
						putchar(i);
						break; 
						
			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
						if(i<0) 
						{ 
							i = -i;
							putchar('-'); 
						} 
						puts(convert(i,10));
						break; 
						
			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
						puts(convert(i,8));
						break; 
						
			case 's': s = va_arg(arg,char *); 		//Fetch string
						puts(s); 
						break; 
						
			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
						puts(convert(i,16));
						break; 
		}	
	} 
	
	//Module 3: Closing argument list to necessary clean-up
	va_end(arg); 
} 
