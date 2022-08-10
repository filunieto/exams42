#include <stdlib.h>
#include <stdio.h>


void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// void	check_leaks(void)
// {
// 	system("leaks swap");
// }


// int main()
// {
// 	int *a;
// 	int *b;
// 	int	c;
// 	int	d;

// 	a = (int *)malloc(sizeof(int));
// 	b = (int *)malloc(sizeof(int));

// 	c = 3;
// 	d = 6;
// 	atexit(check_leaks);

// 	*a = 10;
// 	*b = 15;
// 	printf("los punteros antes a y b: %p, %p. y los valores %i, %i\n", a, b, *a, *b);
// 	ft_swap(a, b);
// 	printf("los punteros despues a y b: %p, %p. y los valores %i, %i\n", a, b, *a, *b);
// 	free(a);
// 	free(b);
// 	printf("----debajo con los valores como direcciones----\n");
// 	printf("los punteros antes c y d: %p, %p. y los valores %i, %i\n", &c, &d, c, d);
// 	ft_swap(&c, &d);
// 	printf("los punteros despues c y d: %p, %p. y los valores %i, %i\n", &c, &d, c, d);
// 	return (0);
// }

// gcc -Wall -Wextra -Werror ft_swap.c -o swap