
void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j;
	int temp;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp  = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
// int		main(void)
// {
// 	int tab[] = { -1, 6, 7, 3, -6, 7, 2, 4, 5, 2147483647, -2147483648 };
// 	unsigned int size = 11;

// 	sort_int_tab(tab, size);

// 	unsigned int i = 0;
// 	while (i < size)
// 	{
// 		printf("element %d: %d\n", i, tab[i]);
// 		i++;
// 	}
// 	return 0;
// }
