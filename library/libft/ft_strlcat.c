/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:14:32 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	i = 0;
	if (dstsize > d_len)
	{
		while (src[i] != '\0' && i < (dstsize - d_len - 1))
		{
			dst[d_len + i] = src[i];
			i++;
		}
		dst[i + d_len] = '\0';
		return (s_len + d_len);
	}
	else
		return (s_len + dstsize);
}

// int	main(void)
// {
// 	size_t	n;
// 	char	*src;
// 	char	*dest;

// 	src = "NULL";
// 	dest = "";
// 	n = 0;
// 	ft_printf("\n %lu", ft_strlcat(dest, "lorem ", 2));
// 	return (0);
// }
