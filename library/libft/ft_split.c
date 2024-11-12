/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:53:48 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/12 16:23:02 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	word_cnt;

	word_cnt = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			word_cnt++;
		while (*s && *s != c)
			++s;
	}
	return (word_cnt);
}

static void	free_string(char **str, size_t str_index)
{
	while (str_index > 0)
		free(str[--str_index]);
}

static void	ft_assign_str(char **ar_split, char const *s, char c)
{
	char const	*temp;
	char		**ar_temp;
	size_t		cnt;

	temp = s;
	cnt = 0;
	ar_temp = ar_split;
	while (*temp)
	{
		while (*s == c)
			++s;
		temp = s;
		while (*temp && *temp != c)
			++temp;
		if (*temp == c || temp > s)
		{
			ar_temp[cnt] = ft_substr(s, 0, temp - s);
			if (!ar_temp[cnt])
				return (free_string(ar_temp, cnt));
			cnt++;
			s = temp;
		}
	}
	ar_temp[cnt] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ar_split;
	int		words;

	ar_split = NULL;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	ar_split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ar_split)
	{
		free((void **)ar_split);
		return (NULL);
	}
	ft_assign_str(ar_split, s, c);
	return (ar_split);
}

// int	main(void)
// {
// 	char	*s;
// 	char	c;
// 	char	**sp;
// 	int		cnt;

// 	s = "hello!";
// 	c = ' ';
// 	cnt = ft_count_words(s, c);
// 	sp = ft_split(s, c);
// 	while (cnt--)
// 		ft_printf("\n %s", sp[cnt]);
// 	return (0);
// }
