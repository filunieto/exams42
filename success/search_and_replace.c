#include <unistd.h>

void putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	search_replace(char *s, char f, char r)
{
	int i = 0;

	char c;
	while (s[i])
	{
		c = s[i];
		if (s[i] == f)
			c = r;
		putchar(c);
		i++;
	}
}

int is_one_letter(char *s)
{
	return (ft_strlen(s) == 1);
}

int	main(int argc, char ** argv)
{
	if (argc == 4 &&  is_one_letter(argv[2]) && is_one_letter(argv[3]))
	{
		search_replace(argv[1], argv[2][0], argv[3][0]);
	}
	write(1 , "\n" , 1);
	return (0);
}
