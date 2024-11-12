/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:46:53 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

static int	ft_islower(unsigned int c)
{
	if (c >= 97 && c <= 122)
		return (c);
	else
		return (0);
}

static int	ft_isupper(unsigned int c)
{
	if (c >= 65 && c <= 90)
		return (c);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (ft_islower((unsigned int)c) || ft_isupper((unsigned int)c))
		return (c);
	else
		return (0);
}

// int	main(void)
// {
// 	int	i;

// 	i = 91;
// 	while (i <= 96)
// 	{
// 		ft_printf(" %d", (ft_isalpha(i)));
// 		i++;
// 	}
// 	return (0);
// }
