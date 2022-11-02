/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:34:52 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/02 18:22:44 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" //to delete in the exam
 
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


/*
	atexit(check_leaks);
*/
void	check_leaks(void)
{
	system("leaks get_next_line ");
}

char	*get_next_line(int fd)
{
	
    // char *string = malloc(10000), *copy = string;
    // while (read(fd, copy, 1) > 0 && *copy++ != '\n');
    // return (copy > string) ? (*copy = 0, string) : (free(string), NULL);

	char	*string;
	char	*copy;

	string = malloc(10000);
	copy = string;
    //while (read(fd, copy, 1) > 0 && *copy++ != '\n');

	while(read(fd, copy, 1) > 0)
	{
		if (*copy++ != '\n')
		{
			
		}
	}
	if (copy > string)
	{
		*copy = 0;
		return (string);
	}
	else
	{
		free(string);
		return (NULL);
	}
	//return (copy > string) ? (*copy = 0, string) : (free(string), NULL);
}

int main(void)
{
	int fd;
	char *line;
	atexit(check_leaks);
	fd = open("text" ,O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}