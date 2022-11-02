/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:24:58 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/09 12:22:43 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*find_first_word(char *s)
{

	while(*s && (*s == ' ' || *s == '\t'))  //while(*s[i] && (s[i] == ' ' || s[i] == '\t'))
	{
		s++;
	}
	return (s);

}

void	write_word(char *s)
{
	while (*s && *s != ' ' && *s != '\t')
	{
		write(1, s, 1);
		s++;
	}
}


int main(int argc, char **argv)
{
	char *s;

	if (argc != 2)
	{
		write(1 , "\n" , 1);
		return (0);
	}
	s = find_first_word(argv[1]);
	write_word(s);
	write(1 , "\n" , 1);
	return (1);
}