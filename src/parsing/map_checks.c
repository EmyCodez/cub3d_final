/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:07:29 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/13 01:53:59 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	create_border_row(char **row, int width)
{
	*row = malloc(width + 3);
	if (!*row)
		return ;
	ft_memset(*row, '1', width + 2);
	(*row)[width + 2] = '\0';
}

void	create_padded_row(char **new_row, char *old_row, int width)
{
	int	len;

	len = ft_strlen(old_row);
	*new_row = malloc(width + 3);
	if (!*new_row)
		return ;
	ft_memset(*new_row, '1', width + 2);
	ft_strncpy(*new_row + 1, old_row, len);
	(*new_row)[width + 1] = '1';
	(*new_row)[width + 2] = '\0';
}

void	free_old_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		free(map->map_data[i]);
		i++;
	}
	free(map->map_data);
}

int	check_valid_characters(t_map *map)
{
	int		i;
	int		j;
	char	*allowed_chars;

	i = 0;
	allowed_chars = "01 NSEW";
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (!ft_strchr(allowed_chars, map->map_data[i][j]))
			{
				ft_printf(RED "Error\n" RESET "Invalid character");
				return (ft_printf(" '%c' in map\n", map->map_data[i][j]), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_player_position(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (ft_strchr("NSEW", map->map_data[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		ft_printf(RED "Error\n" RESET "There should be exactly 1");
		return (ft_printf(" player at start, found %d\n", player_count), 0);
	}
	return (1);
}
