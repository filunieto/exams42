/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:05:49 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/31 11:34:11 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{	
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	print_last_word(char *s)
{
	int i = 0;
	
	if (!s)
		return ;
	while(s[i])
		i++;
	i--;
	while (is_space((s[i])) )
		i--;
	while(!is_space((s[i])) && s[i])
		i--;
	i++;
	while(!is_space((s[i])) && s[i])
		ft_putchar(s[i++]);
		
}


int	main(int argc, char ** argv)
{
	if (argc == 2)
	{
		print_last_word(argv[1]);
	}
	write(1 , "\n" , 1);
	return (0);
}