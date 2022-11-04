#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int char_printed;

void ft_putchar(char c)
{
	write(1, &c, 1);	
	char_printed++;
}

void ft_putstr( char *s)
{
	int i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return ;
	}
	while (s[i])
		ft_putchar(s[i++]);
}

void ft_base_s(long num, unsigned int base, char *decim)
{
	if (num < base)
		ft_putchar(decim[num]);
	else
	{	
		ft_base_s(num/base, base, decim);
		ft_putchar(decim[num % base]);
	}
}

void ft_base_uns(long num, unsigned int base, char *decim)
{
	if (num < 0)
	{
		ft_putchar('-');
		ft_base_s(-num, base, decim);
	}
	else
		ft_base_s(num, base, decim);
}

int ft_printf(char *format, ...)
{
	char_printed = 0;
	int i = 0;
	va_list	ap;
	char base_10[] = "0123456789";
	char base_16[] = "0123456789abcdef";

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				ft_putstr(va_arg(ap, char*));
			}
			else if (format[i] == 'd')
			{
				ft_base_uns(va_arg(ap, int), 10, base_10);
			}
			else if (format[i] == 'x')
			{
				ft_base_uns(va_arg(ap, unsigned int), 16, base_16);
			}
			else
				return (-1);
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (char_printed);
}


int main (void)
{
	//char *s = NULL;
	char s[] = "felipe";
	int i;
	int number = 255;
	i = ft_printf("Felipe funcion: %s, %d, %x \n", s, number , number);
	printf("numero de caracteres mi funcion: %i\n", i);
	i = printf("ORIGIN funcion: %s, %d, %x \n", s, number , number);
	printf("numero de caracteres ORIG funcion: %i\n", i);
	return 0;
}