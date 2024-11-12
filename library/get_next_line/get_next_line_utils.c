/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:48:24 by adhil             #+#    #+#             */
/*   Updated: 2024/10/22 12:59:34 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_g(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*n_str;

	n_str = (char *)malloc(sizeof(char) * (ftstrleng(s1) + ftstrleng(s2) + 1));
	if (!n_str)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		n_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		n_str[i] = s2[j];
		j++;
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

size_t	ftstrleng(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_g(const char *s, int c)
{
	char chr;

	chr = (unsigned char)c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}