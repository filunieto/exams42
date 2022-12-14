/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:34:52 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/03 12:38:17 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h" //to delete in the exam
 
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


/*
	atexit(check_leaks);
*/
void	check_leaks(void)
{
	system("leaks get_next_line ");
}

// char *get_next_line(int fd) Intento 1. funcion ok
// {
// 	char *string = malloc(10000); 
// 	char *copy;

// 	copy = string;
// 	while (read(fd, copy ,1) > 0 && *copy++ != '\n');

// 	if (copy > string)
// 	{
// 		*copy = 0;
// 		return(string);
// 	}
// 	else
// 	{
// 		free(string);
// 		return (NULL);
// 	}
// }

char *get_next_line(int fd)
{
	char *string;
	char *copy;
	
	string =  malloc (10000);
	copy = string;
	while (read(fd, copy, 1) > 0 && *copy++ == '\n');
	// // {
	// 		if (*copy++ == '\n' )
	// 		{
				
	// 		}
	// 		else
	// 			break;
	// // }
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
	
}

int main(void)
{
	int fd;
	char *line;
	//atexit(check_leaks);
	fd = open("text" ,O_RDONLY);
	// line = get_next_line(fd); //string fro, gnl
	// printf("%s", line);

	while (1)
	{
		line = get_next_line(fd); //string fro, gnl
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}


