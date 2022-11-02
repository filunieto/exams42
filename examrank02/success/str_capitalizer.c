#include <unistd.h>
#include <unistd.h>

// int	first_letter(char *s) //Kani
// {
// 	int		i;
// 	char	c;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] >= 97 && s[i] <= 122)
// 		{
// 			c = s[i] - 32;
// 			write(1, &c, 1);
// 			i++;
// 			break ;
// 		}
// 		else if (s[i] >= 65 && s[i] <= 90)
// 		{
// 			c = s[i];
// 			write(1, &c, 1);
// 			i++;
// 			break ;
// 		}
// 		write(1, &s[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// void	capitalize(char *s)
// {
// 	int		i;
// 	char	c;

// 	i = first_letter(s);
// 	while (s[i])
// 	{
// 		if (s[i - 1] == ' ')
// 		{
// 			if (s[i] >= 97 && s[i] <= 122)
// 				c = s[i] - 32;
// 			else
// 				c = s[i];
// 		}
// 		else
// 		{
// 			if (s[i] >= 65 && s[i] <= 90)
// 				c = s[i] + 32;
// 			else
// 				c = s[i];
// 		}
// 		write(1, &c, 1);
// 		i++;
// 	}
// }


// int	main(int argc, char **argv)
// {
// 	int	i;
// 	i = 1;
// 	if (argc > 1)
// 	{
// 		while (i < argc)
// 		{
// 			capitalize(argv[i]);
// 			if (i != (argc -1))
// 				write(1, "\n", 1);
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }



#include <unistd.h>  //funcon de Arian

int ft_isletter_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int ft_isletter_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int     ft_isspace(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}


void    str_capitaliser(char *s)
{
    int i = 0;
	while (s[i])
    {
		while (ft_isspace(s[i]))
		{
			ft_putchar(s[i]);
			i++;
		}
		if (!ft_isspace(s[i])  && s[i])
		{
			if (ft_isletter_lower(s[i]))
			{
				s[i] = s[i] - 32;
			}
			ft_putchar(s[i]);
			i++;
		}
		while (!ft_isspace(s[i]) && s[i])
		{
			if (ft_isletter_upper(s[i]))
				s[i] = s[i] + 32;
			ft_putchar(s[i]);
			i++;
		}
    }
}

// void    str_capitaliser(char *s)
// {
//     while (*s)
//     {
//         while (ft_isspace(*s))
//             ft_putchar(*s++);
//         if (*s && !ft_isspace(*s))
//             ft_putchar(ft_toupper(*s++));
//         while (*s && !ft_isspace(*s))
//             ft_putchar(ft_tolower(*s++));
//     }
// }


int     main(int ac, char **av)
{
    if (ac > 1)
    {
        ++av;
        while (*av)
        {
            str_capitaliser(*av++);
            write(1, "\n", 1);
        }
    }
    return (0);
}


// int     ft_tolower(char c)
// {
//     if (c >= 'A' && c <= 'Z')
// 		return (c = c + 32);
// 	return (0);
// }

// int     ft_toupper(char c)
// {
//     return (c -= (c >= 'a' && c <= 'z') ? 32 : 0);
// }