/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:05:49 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/10 11:34:15 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//aprender funcion split y generalizar para los strings

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
int	main(int argc, char ** argv)
{
	int	len;

	if (argc == 2)
	{
		len = 0;
		while (argv[1][len])
			len++;
		len--;
		while (argv[1][len] && is_space(argv[1][len]))
			len--;
		while (argv[1][len] && !is_space(argv[1][len]))
			len--;
		len++;
		while (argv[1][len] && !is_space(argv[1][len]))
			write(1, &argv[1][len++], 1);
	}
	write(1 , "\n" , 1);
	return (0);
}