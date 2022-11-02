#include <stdio.h>
#include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
	if (!n)
		return 0;
	while (n % 2 == 0)
		n = n / 2;
	return (n == 1);
}

// int main()
// {
	
// 	int n;
// 	int number = 128;
// 	n = is_power_of_2(number);
// 	if (n)
// 		printf("el numeor  %d es potencia de 2\n", number);
// 	else
// 		printf("el numeor  %d NO potencia de 2\n", number);
// 	return 0;
// }