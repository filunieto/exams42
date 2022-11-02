/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:49:54 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/10 15:34:12 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strnlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int main(int arc, char **argv)
{
	int len;
	
	if (arc == 2)
	{
		len = ft_strnlen(argv[1]);
		while (len--)
		{
			write(1, &argv[1][len], 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}

