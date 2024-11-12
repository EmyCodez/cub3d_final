/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:06:43 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_count_digits(int num)
{
	int	cnt_digit;

	cnt_digit = 0;
	if (num <= 0)
		cnt_digit = 1;
	while (num)
	{
		cnt_digit++;
		num /= 10;
	}
	return (cnt_digit);
}

static char	*ft_getnumber(char *str, long num, int len)
{
	while (len-- && num != 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_count_digits(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[len] = 0;
	return (ft_getnumber(str, num, len));
}

// int	main(void)
// {
// 	ft_printf("\n %s>>", ft_itoa(-2147483648));
// 	ft_printf("\n %s", ft_itoa(-52));
// 	return (0);
// }
