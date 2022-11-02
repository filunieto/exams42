/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:13:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/08/10 18:40:09 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;
	t_list *current;

	if (!begin_list)
		return (0);
	i = 0;
	current = begin_list;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}