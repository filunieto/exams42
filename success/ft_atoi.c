
//#include <stdio.h> //
int ft_isspace(char c)
{
	return (c <= 32);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int nbr;
	int sign = 1;
	nbr = 0;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while(ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}



// int		main(int argc, char **argv)
// {
// 	int i = argc;

// 	i = i +1;
// 	printf("%d",ft_atoi(argv[1]));
// 	return(0);
// }
