/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:48:10 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/13 01:54:49 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_line_lengths(t_map *map)
{
	int	i;
	int	prev_len;
	int	curr_len;
	int	next_len;

	i = 1;
	while (i < map->map_height - 1)
	{
		prev_len = ft_strlen(map->map_data[i - 1]);
		curr_len = ft_strlen(map->map_data[i]);
		next_len = ft_strlen(map->map_data[i + 1]);
		if (curr_len > prev_len && curr_len > next_len)
		{
			printf(RED "Error\n" RESET
				"Line %d is longer than both the previous and next lines\n",
				i + 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map_structure(t_map *map)
{
	if (!check_line_lengths(map))
	{
		ft_printf(RED "Error\n" RESET "Map has invalid structure");
		ft_printf(" due to line length inconsistency.\n");
		return (0);
	}
	ft_printf("Map structure is valid.\n");
	return (1);
}

void	make_map_square(t_map *map)
{
	int		i;
	int		max_width;
	char	**new_map;
	int		len;

	i = 0;
	max_width = 0;
	len = 0;
	while (i < map->map_height)
	{
		len = ft_strlen(map->map_data[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	new_map = malloc(sizeof(char *) * (map->map_height + 2));
	create_border_row(&new_map[0], max_width);
	i = -1;
	while (++i < map->map_height)
		create_padded_row(&new_map[i + 1], map->map_data[i], max_width);
	create_border_row(&new_map[map->map_height + 1], max_width);
	free_old_map(map);
	map->map_data = new_map;
	map->map_height += 2;
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_data[0][i] && map->map_data[map->map_height - 1][i])
	{
		if (map->map_data[0][i] != '1' && map->map_data[0][i] != ' ')
			return (ft_printf(RED "Error\nTop boundary not closed\n"), 0);
		if (map->map_data[map->map_height - 1][i] != '1'
			&& map->map_data[map->map_height - 1][i] != ' ')
			return (ft_printf(RED "Error\nBottom boundary not closed\n"), 0);
		i++;
	}
	i = 0;
	while (map->map_data[i])
	{
		if (map->map_data[i][0] != '1' && map->map_data[i][0] != ' ')
			return (ft_printf(RED "Error\nLeft boundary not closed\n"), 0);
		j = ft_strlen(map->map_data[i]) - 1;
		if (map->map_data[i][j] != '1' && map->map_data[i][j] != ' ')
			return (ft_printf(RED "Error\nRight boundary not closed\n"), 0);
		i++;
	}
	return (1);
}
