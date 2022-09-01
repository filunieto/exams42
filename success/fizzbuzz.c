#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	
	char c;

	if (nbr < 0)
	{
		c = '-';
		ft_putchar(c);
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		c = '0' + nbr;
		ft_putchar(c);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr/10);
		ft_putnbr(nbr % 10);
	}	
}

void fizzbuzz()
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (!(i % 3) && (i % 5))
		{
			write(1, "fizz\n", 5);
			//i++;
		}
		else if (!(i % 5) && (i % 3))
		{
			write(1, "buzz\n", 5);
			//i++;
		}
		else if (!(i % 5) && !(i % 3))
		{
			write(1, "fizzbuzz\n", 9);
			//i++;
		}
		else
		{			
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
}

int	main()
{
	fizzbuzz();
	return (0);
}