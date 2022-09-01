#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{	
	write(1, &c, 1);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	expand_str(char *s)
{
	int i = 0;
	if (!s)
		return ;
	while(ft_is_space(*s))
		s++;
	while (s[i])
	{
		while(!ft_is_space(s[i]) && s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		while(ft_is_space(s[i]))
		{
			i++;
		}
		if ((s[i]))
			write(1 , "   " , 3);
	}
}


int	main(int argc, char ** argv)
{
	if (argc == 2)
	{
		expand_str(argv[1]);
	}
	write(1 , "\n" , 1);
	return (0);
}