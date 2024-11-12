/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:51:21 by esimpson          #+#    #+#             */
/*   Updated: 2023/11/30 11:54:10 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	to_lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

int	get_digit(char ch, int base)
{
	int	max_digit;

	if (base <= 10)
		max_digit = base + '0';
	else
		max_digit = base - 10 + 'a';
	if (ch >= '0' && ch <= '9' && ch <= max_digit)
		return (ch - '0');
	else if (ch >= 'a' && ch <= 'f' && ch <= max_digit)
		return (ch + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	digit;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		++str;
	if (*str++ == '0')
	{
		if (*str == 'X' || *str == 'x')
			++str;
	}
	digit = get_digit(to_lower(*str), str_base);
	while (digit >= 0)
	{
		result = result * str_base + digit;
		++str;
		digit = get_digit(to_lower(*str), str_base);
	}
	return (result * sign);
}
