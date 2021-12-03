#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_putchar(char c);
int			printpointer(void *ptr);
int			printstring(char *s);
int			printunint(long long n);
int			printhex(unsigned int n, char c);
int			writenull(void);
long long	ft_intlen(long long val);

int			ft_printf(const char *str, ...);

#endif