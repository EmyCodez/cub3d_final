/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:58:29 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *str)
{
	long	number;
	int		sign;
	int		count;

	number = 0;
	count = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		count++;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = number * 10 + *str - 48;
		str++;
	}
	if (count > 1)
		return (0);
	else
		return ((int)(number * sign));
}

// int	main(void)
// {
// 	char	str[];

// 	str[] = "+2147483648";
// 	ft_printf("%d", ft_atoi(str));
// 	return (0);
// }
