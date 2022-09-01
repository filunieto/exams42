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
	return (number_words);
	
}

void free_array(char	**array_words, int i)
{
	while (i >= 0)
	{
		free(array_words[i]);
		i--;
	}
}

char    **ft_split(char *str)
{
	int number_words;
	char	**array_words;
	int	i;

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

// int main()
// {
// 	char *str;
// 	char **array_main;

// 	str = "  Hola pare	mi mama \n me mima.  ";
// 	array_main = ft_split(str);
// 	print_array(array_main);
// 	return (0);
// }

