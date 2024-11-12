/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:35:56 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = 0;
}

// int	main(void)
// {
// 	int src[] = {1, 2, 3, 4, 5,6 ,7};

// 	size_t i = 0;
// 	size_t n = sizeof(src) / sizeof(src[0]);
// 	ft_bzero(src, sizeof(src));
// 	ft_printf("\n bzero ");
// 	while (i < n)
// 	{
// 		ft_printf("%d \t ", src[i]);
// 		i++;
// 	}

// 	return (0);
// }