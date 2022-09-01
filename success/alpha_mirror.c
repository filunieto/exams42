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


void	alpha_mirror( char *s)
{
	int i = 0;

	char c;
	while (s[i])
	{
		c = s[i];
		if (ft_isletter_upper(s[i]))
			c = 155 - s[i];
		if (ft_isletter_lower(s[i]))
			c = 219 - s[i];
		putchar(c);
		i++;
	}
}

int main(int argc, char ** argv)
{
	if (argc == 2)
	{
		alpha_mirror(argv[1]);
	}
	putchar('\n');
	return (0);
}