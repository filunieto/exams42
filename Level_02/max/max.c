#include <stdlib.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int max;
	max = 0;

	if (!len)
		return (max);
	while (len--)
	{
		if (tab[len] > max)
		{
			max = tab[len];
		}
	}
	return(max);
}

// int main(void)
// {
// 	int tab[4] = {1 , 2 , 3 , 4};
// 	int len = 4;

// 	int	tab1[0];

// 	int	*tab2;
// 	int len2 = 6;

// 	tab2 = (int *)malloc(sizeof(int) * len2);
// 	for (int j = 0; j < len2; j++)
// 	{
// 		tab2[j] = j * j;
// 	} 

// 	printf("maximo %i\n", max(tab, len));
// 	printf("maximo %i\n", max(tab1, 0));
// 	printf("maximo calculado con malloc %i\n", max(tab2, len2));
// 	return (0);
// }

// gcc -Wall -Wextra -Werror max.c