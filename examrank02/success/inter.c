#include <unistd.h>

#include <unistd.h>
#include <stdio.h>



int is_behind(char *behind, char c, int position)
{
	int i = 0;
	while (i < position)
	{
		if (behind[i] == c)
			return(1);
		i++;
	}
	return (0);
}


void inter(char *first, char *second)
{
	int  i = 0;
	int j = 0;

	while (first[i])
	{
		j = 0;
		while(second[j])
		{
			if (second[j] == first[i] && (!is_behind(first, first[i], i)))
			{
				write(1, &first[i], 1);
				break;
			}
			j++;
		}
		i++;
    }
}


int main(int argc, char **av)
{
    if (argc == 3)
    {
		inter(av[1], av[2]);
    }
    write(1, "\n", 1);
    return (0);
}




// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }


// void inter(char *s1, char *s2)
// {
// 	int i = 0;
// 	int j = 0;
// 	if(!s1 || !s2)
// 		return ;
// 	// char *behind;
// 	// behind = s1;
// 	while (s1[i])
// 	{
// 		j = 0;
// 		while (s2[j])
// 		{
// 			if (s1[i] == s2[j])
// 			{
// 				if (!is_behind(s1, s1[i], i))
// 				{
// 					ft_putchar(s1[i]);
// 					//i++;
// 					//j++;
// 					break;
// 				}
// 			}
// 			++j;
// 		}
// 		i++;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	int	i;

// 	i = 0;
// 	if (ac == 3)
// 	{
// 		inter(av[1], av[2]);
// 	}
// 	ft_putchar('\n');
// 	return (0);
// }
