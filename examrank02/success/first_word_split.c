/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:41:36 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/11 11:33:56 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_array (char **array_words)
{
	for (int i = 0; array_words[i]; i++)
	{
		printf("imprimo array. Para el indice %i, string: %s\n",i, array_words[i]);
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char *create_word(char *str)
{
	char *dest;
	int i;
	int j;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	dest =  (char *)malloc(sizeof(char) * i);
	if (!dest)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

int	count_words(char *str)
{
	int	i;
	int	number_words;

	i = 0;
	number_words = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && (!(str[i + 1]) || ft_isspace(str[i + 1]))) //importante 
			number_words++;
		i++;
	}
	//printf("numero de palabras %i\n", number_words);
	return (number_words);
	
}

void free_array(char	**array_words, int i)
{
	while (i >= 0)
	{
		free(array_words[i]);
		i--;
	}
	free (array_words);
}

char    **ft_split(char *str)
{
	int number_words;
	char	**array_words;
	int	i;

	//printf("hasta aqui ok 1 \n");
	if (!str)
		return (NULL); 
	number_words = count_words(str);
	array_words = (char	**)malloc((sizeof (char *) * number_words) + 1) ;
	if (!array_words)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	i = 0;
	while (*str)
	{
		array_words[i] = create_word(str);
		if (!array_words[i])
			free_array(array_words, i);
		i++;
		while (!ft_isspace(*str) && *str)
			str++;
		while (ft_isspace(*str) && *str)
			str++;
	}
	array_words[i] = 0;
	return (array_words);
}

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char** argv)
{
	char	**array_words;
	int len_word;
	
	printf("hasta aqui ok 0 \n");
	

	if (argc == 2)
	{
		//printf("hasta aqui ok 1 \n");

		array_words = ft_split(argv[1]);
		//return (0);
		//print_array(array_words);
		len_word = ft_strlen(array_words[0]); //esta funcion hay que protegerla, para el caso en el que tengamos un NULL
		if (array_words[0] != NULL)
			write (1 , array_words[0] , len_word);
			
		free_array(array_words, len_word); //tendria que hacer un free de todas las palabras mas el array
	}
	write (1 , "\n" , 1);
	return (0);
}