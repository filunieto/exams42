/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:18:45 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/02 23:07:42 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//man va_arg 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int r;

void	ft_putchar(char c)
{
	write (1, &c, 1);
	r++;
}

void base_uns(long num, unsigned int base, char *digits)
{
	if (num < base)
		ft_putchar((digits[num]));
	else
	{
		base_uns(num/base, base, digits);
		ft_putchar(digits[num % base]);
	}
}

void	ft_putstr(char *s)
{
	int i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
//generic funtion which will call 
void	base_s(long num, unsigned int base, char *digits)
{
	if (num < 0)
	{
		ft_putchar('-');
		base_s(-num, base, digits);
	}
	else
	{
		base_s(num / base, base, digits);
	}
}

int ft_printf(const char *format, ...)
{
	r = 0;
	int i = 0;
	va_list args;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i] == 'd')
				base_s(va_arg(args, int), 10, "0123456789");
			else if (format[i] == 'x')
				base_s(va_arg(args, unsigned int), 16, "0123456789abcdef");
			else
				return(-1);
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (r);
	
}