/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:51:36 by esimpson          #+#    #+#             */
/*   Updated: 2024/10/22 13:52:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	begin;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)(s1));
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	str_trim = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!str_trim)
		return (NULL);
	i = 0;
	while (begin < end)
		str_trim[i++] = s1[begin++];
	str_trim[i] = 0;
	return (str_trim);
}

// int	main(void)
// {
// 	char	*s_trim;

// 	s_trim = ft_strtrim("", "");
// 	ft_printf("\n trimmed string=%s", s_trim);
// 	return (0);
// }
