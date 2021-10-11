#include <stddef.h>
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

int check_conversion(char c, va_list ap)
{
	if (c == 'c')
		printchar(ap);
	else if (c == 's')
		printstring(ap);
	else if (c == 'p')
		printpointer(ap);
	else if (c == 'd' || c == 'i')
		printint(ap);
	else if (c == 'u')
		printunint(ap);
	else if ( c == 'x' || c == 'X')
		printhex(ap);
	else if (c == '%')
		printpercent();
}

int ft_printf(const char *str, ...)
{
	size_t	ret;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		while (*str != '%')
		{
			ft_putchar(*str);
			str++;
		}
		str++;
		check_conversion(*str, ap);
	}
	va_end(ap);
	return (ret);
}
