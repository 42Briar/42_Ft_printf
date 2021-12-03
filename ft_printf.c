#include "ft_printf.h"

static int	check(char str, va_list ap)
{
	int	count;

	count = 0;
	if (str == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str == 's')
		return (printstring(va_arg(ap, char *)));
	else if (str == 'p')
		return (printpointer(va_arg(ap, void *)));
	else if (str == 'd' || str == 'i')
		return (printunint(va_arg(ap, int)));
	else if (str == 'u')
		return (printunint(va_arg(ap, unsigned int)));
	else if (str == 'x' || str == 'X')
		return (printhex(va_arg(ap, unsigned int), str));
	else if (str == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	printer(const char *str, va_list ap)
{
	int	count;
	int	temp;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			temp = check(*str, ap);
			if (temp == -1)
			{
				temp += 2;
				write(1, &(*str), 1);
			}
			count += temp;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	ret;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	ret += printer(str, ap);
	va_end(ap);
	return (ret);
}
