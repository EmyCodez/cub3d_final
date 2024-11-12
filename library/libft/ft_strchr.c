/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:20:23 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

// int	main(void)
// {
// 	// 	char str[] = "Welcome Everyone";
// 	// 	int c;
// 	// 	char *locate;
// 	// 	c = '\0';
// 	// 	locate = ft_strchr(str, c);
// 	// 	if (locate != NULL)
// 	// 		ft_printf("\n %c found in %s", c, locate);
// 	// 	else
// 	// 		ft_printf("\n %c not found in %s", c, str);
// 	char s[] = "tripouille";
// 	ft_printf("%s",ft_strchr(s, 't' + 256));
// 	return (0);
// }
