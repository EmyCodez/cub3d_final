/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:17:16 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0 && *ptr != (unsigned char)c)
	{
		ptr++;
		n--;
	}
	if (n)
		return ((void *)ptr);
	else
		return (NULL);
}

// int	main(void)
// {
// 	//char	*s;
// 	//s = "Qwertyuiop";
// 	ft_printf("%s", (char *)memchr(NULL, 1, 1));
// 	return (0);
// }
