#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int *range;
	int len;
	int i = 0;

	len = 0;
	if (start > end) // start mayor  que end (0,-3)
		len = start - end;
	else // start menor o igual que end (1, 3)
		len = end - start;
	range =  malloc(sizeof(int) * len + 1);
	if (!range)
		return NULL;
	while (i <= len)
	{
		if (start > end)
		{
  			//range[i] = start++; si emepzamos a imprimr desde una esquina
			range[i] = end++;
		}
		else
		{
			//range[i] = start--;
			range[i] = end--;
		}
		i++;
	}
	// i = 0;
	// while(len-- + 1)
	// {
	// 	printf("%d,", range[i++]);
	// }
	return (range);

}

// int main(int argc, char ** argv)
// {


// 	if (argc == 3)
// 	{
// 		int *range;
// 		range = ft_rrange(atoi(argv[1]), atoi(argv[2]));
// 		putchar('\n');
// 		free(range);
// 	}

// 	return (0);
// }