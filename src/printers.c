#include "ft_printf.h"

int printunint(long long n)
{
	
	unsigned long long	num;
	int				count;
	char			c;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
		num = n;
	if (num > 9)
		count += printunint(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int printstring(char *s)
{
	int count;

	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

static int	ft_putnbr_base(unsigned long long nbr)
{
	int				i;
	int				count;
	char *base = "0123456789abcdef";
	unsigned char	output[1000];

	i = 0;
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
		count ++;
	}
	while (nbr != 0)
	{	
		output[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &(base[(output[i])]), 1);
		count++;
	}
	return (count);
}

int printpointer(void* ptr) 
{
	unsigned long long p = (unsigned long long)ptr;

	return (ft_putnbr_base(p));

}