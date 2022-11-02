#include <unistd.h>

void putchar(char c)
{	
	write(1, &c, 1);
}

int ft_isletter_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int ft_isletter_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int ft_1half(char c)
{
	return ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'));
}

int ft_2half(char c)
{
	return ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'));
}

void	rot_13( char *s)
{
	int i = 0;

	char c;
	while (s[i])
	{
		c = s[i];
		if (ft_1half(s[i]))
			c = s[i] + 13;
		if (ft_2half(s[i]))
			c = s[i] - 13;
		putchar(c);
		i++;
	}
}

int main(int argc, char ** argv)
{
	if (argc == 2)
	{
		rot_13(argv[1]);
	}
	putchar('\n');
	return (0);
}