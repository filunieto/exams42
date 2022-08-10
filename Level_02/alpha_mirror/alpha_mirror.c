/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:07:23 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/09 17:07:46 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	char c;
	
	int i = 0;
	if (arc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				c = 219 - argv[1][i]; // A + Z == 97 + 122 = 219
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				c = 155 - argv[1][i];
			else
				c = argv[1][i];
			write (1, &c, 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}