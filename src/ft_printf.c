#include "ft_printf.h"
/*
	Printf return the number of characters written, on failure it returns -1



	c    char
	s    char *
	p    void * (to print pointer's adress)
	d/i	 int
	u    unsigned int
	x/X	 number in hex(lcase/upcase)
	%	percent sign

*/

int printer(const char *str, va_list ap)
{
	int count;
	
	count = 0;
	while (*str)
	{
		if(*str == '%')
		{
			str++;
			if (*str == 'c')
				count += ft_putchar(va_arg(ap, int));
			else if (*str == 's')
				count += printstring(va_arg(ap, char *));
			else if (*str == 'p')
				count += printpointer(va_arg(ap, void *));
			else if (*str == 'd' || *str == 'i')
				count += printunint(va_arg(ap, int));
			else if (*str == 'u')
				count += printunint(va_arg(ap, unsigned int));
			// else if (*str == 'x' || *str == 'X')
				// count += printhex(va_arg(ap, unsigned int), *str);
			else if (*str == '%')
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(*str);
		str++; 
	}
	return count;
}



int ft_printf(const char *str, ...)
{
	size_t	ret;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	ret += printer(str, ap);
	va_end(ap);
	return (ret);
}

int main()
{
	char *str = "aagl;kjdfa";

	ft_printf("%d\n", ft_printf("abc: %%\n"));
	printf("%d\n", printf("abc: %%\n"));
}
