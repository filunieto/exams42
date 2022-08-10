/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:34:29 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/09 12:57:34 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void putchar(char c)
{
	write (1, &c, 1);
}

void putnbr(int nbr)
{
	char  c;

	if (nbr < 0)
	{
		c = '-';
		putchar(c);
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		c = '0' + nbr;
		putchar(c);
	}
	else
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
}

