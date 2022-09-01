#include <stdio.h>//
#include <stdlib.h>//

int ft_isspace(char c)
{
	return (c <= 32);
}

int		isvalid(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}




int	ft_isvalid(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int nbr = 0;
	int sign = 1;


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
	while (isvalid(*str))
	{
		nbr = nbr * str_base + ft_isvalid(*str);
		str++;
	}
	return (nbr * sign);
}

// int		main(int ac, char **av)//
// {//
// 	if (ac == 3)//
// 		printf("result: %d\n", ft_atoi_base(av[1], atoi(av[2])));//
// 	return (0);//
// }//