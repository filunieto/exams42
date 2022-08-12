# exam02
42 exam exercises rank 02 C

cada vez que use malloc. Asegurar con un Null si hay problema

compilar siempre , paar ver errores previos
alias T="gcc -Wextra -Wall -Werror"

# include <limits.h>

Funciones importantes
ft_split

atoi
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + ((str[i]) - '0');
		if (nb > 2147483647 && sign == 1)
			return (-1);
		if (nb > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (sign * (int)nb);

itoa
cuenta cifras para malloquear (incluyend el signo menos)
Si es 0 , lo tratamos aparte.
nullterminamos el string, anadismo signo si lo hay
char	*str_numb(char *number, unsigned int n, int cipher)
{
	while (n > 0)
	{
		number[cipher--] = n % 10 + '0';
		n = n / 10;
	}
	return (number);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 +'0');
}

header
Aplicar funciones a listas

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*curr;

	curr = begin_list;
	while (curr)
	{
		(*f)(curr->data);
		curr = curr->next;
	}
}


Hacer:
inter.c
fprime.c

Revisar
hidenp

Ft_split
Si la usamos, tener cuidado l usar un write , si imprime un NULL
Para verificar un segmentation faul. Usar (printf + return)
Atencion cuando el input es NULL.
Proteger todas las funciones (includias ft_strlen)