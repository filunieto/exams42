#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c)
{	
	write(1, &c, 1);
}

int	pgcd(int n1, int n2)
{
	int max_den;
	int max_numero;
	int min_numero;

	if (n1 > n2)
	{
		max_den = n2; //menor de los umeros
		max_numero = n1;
		min_numero = n2;


	}
	else
	{
		max_den = n1;
		max_numero = n2;
		min_numero = n1;

	}
	while (max_den > 0)
	{
		if ((max_numero % max_den == 0) && (min_numero % max_den == 0))
			return (max_den);
		max_den--;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int max_denom;
	if (argc == 3 && atoi(argv[1]) && atoi(argv[2]))
	{
		max_denom = pgcd(atoi(argv[1]), atoi(argv[2]));
		printf("%d", max_denom);
	}
	ft_putchar('\n');
	return (0);
}