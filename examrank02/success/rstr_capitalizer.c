#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Leer el enunciado!!  capitaliza solo la ultima letra

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

int ft_isletter_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int ft_isletter_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	end_of_word(char c)
{
	return (c == '\0' || is_space(c));
}

int	is_word(char c)
{
	return (c != '\0' && !is_space(c));
}

void str_capitalizer(char *str)
{
	char c;
	int i = 0;
	while (str[i])
	{
		c = str[i];
		while (is_space(str[i]))
		{
			ft_putchar(c);
			i++;
		}
		while (is_word(str[i]))
		{
			if (ft_isletter_lower(str[i]) && end_of_word(str[i + 1])) //ultima letra
			{
				c = str[i] - 32;
			}
			else if (ft_isletter_upper(str[i]) && is_word(str[i + 1]))
			{
				c = str[i] + 32;
			}
			ft_putchar(c);
			i++;
		}
	}
}

int	main(int argc, char ** argv)
{
	if (argc > 1)
	{
		int i = 1;
		while(i < argc)
		{
			str_capitalizer(argv[i]);
			i++;
		}
	}
	write(1 , "\n" , 1);
	return (0);
}

