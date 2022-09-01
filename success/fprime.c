#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_isprime(int n)
{
	int i = 2;
	if (n == 0 || n == 1)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void fprime(int n)
{
	int i = 2;
	if (n == 1)
	{
		printf("1");
		return ;
	}
	else
	{
		while (i <= n)
		{
			while (ft_isprime(i) && (n % i) == 0)
			{
				if (i == n)
					printf("%d", i);
				else
					printf("%d*", i);
				n = n / i;
				i = 2;
				break ;
			}
			i++;
		}
	}

}

int main(int argc, char **argv)
{
	if (argc == 2 && atoi(argv[1]))
	{
		fprime( atoi(argv[1]));
	}
	ft_putchar('\n');
	return(0);
}