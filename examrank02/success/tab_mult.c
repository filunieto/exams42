#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(char *str)
{
	int nbr;
	nbr = 0;
	int sign = 1;
	if (!str)
		return nbr;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while(ft_isdigit(*str) && *str)
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
	
}

void tab_mul(int nbr)
{
	int i = 1;
	while(i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(nbr);
		write(1, " = ", 3);
		ft_putnbr(nbr * i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_atoi(argv[1]))
	{
		tab_mul(ft_atoi(argv[1]));
	}
	else
		write(1, "\n", 1);
	return (0);
}
