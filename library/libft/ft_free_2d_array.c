/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:56:45 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/12 16:16:10 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_array(char ***map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (map[i] && (*map)[i])
	{
		ft_free_ptr((void **)&((*map)[i]));
		i++;
	}
	ft_free_ptr((void **)map);
}
