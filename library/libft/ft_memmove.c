/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:07:39 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*sr;
	unsigned char		*dt;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	sr = (const unsigned char *)src;
	dt = (unsigned char *)dst;
	i = 0;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
			dt[len] = sr[len];
		return (dst);
	}
}
// int	main(void)
// {
// 	int src[] = {10, 20, 30, 40, 50};
// 	size_t n = sizeof(src) / sizeof(src[0]);
// 	int dest[] = {1, 2, 3, 4, 5,6};
// 	size_t i;
// 	i = 0;

// 	ft_memmove(dest, src, sizeof(int) * 3);
// 	//ft_printf("\nCopied array is %s", src);
// 	while (i < sizeof(dest))
// 	{
// 		ft_printf("%d ", dest[i]);
// 		i++;
// 	}

// 	return (0);
// }