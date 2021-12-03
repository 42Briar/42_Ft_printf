#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	writenull(void)
{
	write(1, "(null)", 6);
	return (6);
}

long long	ft_intlen(long long val)
{
	int	i;

	i = 0;
	if (val < 0)
		val = -val;
	while (val > 9)
	{
		i++;
		val /= 10;
	}
	return (i);
}
