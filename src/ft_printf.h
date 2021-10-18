#ifndef FT_PRINTF_H
# define FT_PRINTF_h

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int ft_putchar(char c);
int printpointer(void* ptr);
int printstring(char *s);
int printunint(long long n);
int printhex(unsigned int n, char c);

#endif