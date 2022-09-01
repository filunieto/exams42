#include "list.h"

// int comp(int a, int b)
// {
// 	return (a <= b);
// }

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *current;

	int swap = 1;
	int temp;
	if (!lst)
		return (NULL);
	current = lst;
	while (swap)
	{
		swap = 0;
		while (current && current->next)
		{
			if (!cmp(current->data, current->next->data))
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swap = 1;
			}
			current = current->next;
		}
		current = lst;
	}
	return (lst);
}

// void print_list(t_list *current)
// {
// 	while(current)
// 	{
// 		printf("%d\n", current->data);
// 		current = current->next;
// 	}
// }

// int main(void)
// {
// 	t_list *current;
// 	current = (t_list *)malloc(sizeof(t_list));
// 	current->data = 10;
// 	current->next = NULL;

// 	t_list *current2;
// 	current2 = (t_list *)malloc(sizeof(t_list));
// 	current2->data = 5;
// 	current2->next = NULL;
// 	current->next = current2;

// 	t_list *current3;
// 	current3 = (t_list *)malloc(sizeof(t_list));
// 	current3->data = 1;
// 	current3->next = NULL;
// 	current2->next = current3;

// 	t_list *current4;
// 	current4 = (t_list *)malloc(sizeof(t_list));
// 	current4->data = 1;
// 	current4->next = NULL;
// 	current3->next = current4;

// 	print_list(current);
// 	sort_list(current, comp);
// 	printf("sorted list\n");
// 	print_list(current);
// 	return (0);
// }