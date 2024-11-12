/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:36:01 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*sr;
	unsigned char		*dt;
	size_t				i;

	i = 0;
	sr = (unsigned const char *)src;
	dt = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dt[i] = sr[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	int	n;
// 	int	i;
// 	int	dest[10];
// 	int	src[10];

// 	src[10] = {10, 20, 30, 40, 50};
// 	n = 10;
// 	i = 0;
// 	ft_memcpy(dest, src, sizeof(src));
// 	ft_printf("\nCopied array is %s\n", ft_memcpy(NULL, NULL, sizeof(src)));
// 	while (i < n)
// 	{
// 		ft_printf("%d ", dest[i]);
// 		i++;
// 	}
// }
