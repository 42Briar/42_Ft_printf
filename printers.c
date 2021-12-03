#include "ft_printf.h"

int	printunint(long long n)
{
	unsigned long long	num;
	int					count;
	char				c;

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

int	printstring(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (writenull());
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

static int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int				i;
	int				count;
	unsigned char	*output;

	i = 0;
	count = 0;
	output = (unsigned char *)malloc(sizeof(char) * ft_intlen(nbr));
	while (nbr != 0)
	{	
		output[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &(base[(output[i])]), 1);
		count++;
		i--;
	}
	free(output);
	return (count);
}

int	printpointer(void *ptr)
{
	unsigned long long	p;

	p = (unsigned long long)ptr;
	write(1, "0x", 2);
	if (ptr == NULL)
	{
		write(1, "0", 1);
		return (3);
	}
	return (ft_putnbr_base(p, "0123456789abcdef") + 2);
}

int	printhex(unsigned int n, char c)
{
	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	if (c == 'x')
		return (ft_putnbr_base(n, "0123456789abcdef"));
	else
		return (ft_putnbr_base(n, "0123456789ABCDEF"));
}
