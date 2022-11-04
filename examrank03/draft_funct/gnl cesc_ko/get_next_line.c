/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:34:52 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/03 10:44:36 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" //to delete in the exam
 
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

char	*get_next_line(int fd)
{
	char			*str;
	static char		*string;
	char			*tmp;

	if ((read (fd, 0, 0) == -1) || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_file(fd, string);
	if (!string)
		return (NULL);
	if (chr_src(string, '\n') > 0 || string [0] == '\n')
	{
		str = make_string(NULL, string, chr_src(string, '\n') + 1);
		tmp = string;
		string = make_string(NULL, &string[chr_src(string, '\n') + 1], -1);
		free(tmp);
		return (str);
	}
	str = make_string(NULL, string, -1);
	if (string)
		free(string);
	string = NULL;
	return (str);
}

char	*read_file( int fd, char *string)
{
	ssize_t		n_byte;
	char		*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n_byte = 1;
	while (n_byte > 0)
	{
		n_byte = read(fd, buff, BUFFER_SIZE);
		buff[n_byte] = '\0';
		if (chr_src (buff, '\n') > 0 || buff[0] == '\n')
			return (ft_return_string(string, buff));
		string = make_string(string, buff, -1);
	}
	free (buff);
	if (string[0] == '\0')
	{
		free(string);
		string = NULL;
	}
	return (string);
}

char	*make_string(char *tail, char *head, size_t n_byte)
{
	size_t	j;
	size_t	i;
	char	*str;

	i = str_len(tail);
	j = 0;
	while (head[j] && j < n_byte)
		j++;
	str = malloc(i + j + 1);
	if (!str)
		return (NULL);
	str = ft_cpy(j, str, tail, head);
	if (tail)
		free (tail);
	return (str);
}

int main(void)
{
	int fd;
	char *line;
	//atexit(check_leaks);
	fd = open("text" ,O_RDONLY);
	line = get_next_line(fd); //string fro, gnl
	printf("%s", line);

	// while (1)
	// {
	// 	line = get_next_line(fd); //string fro, gnl
	// 	if (!line)
	// 		break;
	// 	printf("%s", line);
	// 	free(line);
	// }
	return (0);
}