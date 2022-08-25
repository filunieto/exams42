/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:50:02 by galpers           #+#    #+#             */
/*   Updated: 2022/08/24 22:40:28 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    while (n % 2 == 0)
        n = n / 2;
    if (n == 1)
        return 1;
    else
        return 0;
}

// int	main(void)
// {
// 	printf("%d\n", is_power_of_2(1024));
// 	printf("%d\n", is_power_of_2(1023));
// 	printf("%d\n", is_power_of_2(0));
// 	printf("%d\n", is_power_of_2(1));
// }