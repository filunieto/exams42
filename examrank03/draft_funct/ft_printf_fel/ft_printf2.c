/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:06:11 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/03 11:47:53 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int r;

void ft_putchar(char c)
{
	write(1, &c, 1);
	r++;
}

void ft_base_s(long num, unsigned int base, char *decim)
{
	if (num < base)
		ft_putchar(decim[num]);
	else
	{
		ft_base_s(num / base, base, decim);
		ft_putchar(decim[num % base]); //ATENCION
	}
}

void	ft_putstr(char *s)
{
	int i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return ; //olvidado

	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
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
	r = 0;
	int i = 0;

	va_list ap;
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
			else if (format[i] == 'x')
			{
				ft_base_uns(va_arg(ap, unsigned int), 16, "0123456789abcdef"); //ATENCION
			}
			else if (format[i] == 'd')
			{
				ft_base_uns(va_arg(ap, int), 10, "0123456789"); //ATENCION
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
	return (r); //ATRNCION
}

int main (void)
{
	char *s = NULL;
	//char s[] = "felipe";
	int i;
	int number = -255;
	i = ft_printf("Felipe funcion: %s, %d, %x \n", s, number , number);
	printf("numero de caracteres mi funcion: %i\n", i);
	i = printf("ORIGIN funcion: %s, %d, %x \n", s, number , number);
	printf("numero de caracteres ORIG funcion: %i\n", i);
	return 0;
}
