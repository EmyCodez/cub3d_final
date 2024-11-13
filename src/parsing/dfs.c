/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:18:44 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/12 23:46:30 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	dfs_replace_spaces(t_map *map, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= map->map_height
		|| y >= (int)ft_strlen(map->map_data[x]))
		return (1);
	if (visited[x][y])
		return (1);
	visited[x][y] = 1;
	if (map->map_data[x][y] == ' ')
	{
		ft_printf("Replacing space at (%d, %d) with '0'\n", x + 1, y + 1);
		map->map_data[x][y] = '1';
	}
	if (!dfs_replace_spaces(map, x + 1, y, visited))
		return (0);
	if (!dfs_replace_spaces(map, x - 1, y, visited))
		return (0);
	if (!dfs_replace_spaces(map, x, y + 1, visited))
		return (0);
	if (!dfs_replace_spaces(map, x, y - 1, visited))
		return (0);
	return (1);
}

int	allocate_visited(int ***visited, int height, int width)
{
	int	i;

	*visited = malloc(sizeof(int *) * height);
	if (!*visited)
		return (0);
	i = 0;
	while (i < height)
	{
		(*visited)[i] = malloc(sizeof(int) * width);
		if (!(*visited)[i])
			return (0);
		ft_memset((*visited)[i], 0, sizeof(int) * width);
		i++;
	}
	return (1);
}

int	find_start_position(t_map *map, int *start_x, int *start_y)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < ft_strlen(map->map_data[i]))
		{
			if (ft_strchr("0NSEW", map->map_data[i][j]))
			{
				*start_x = i;
				*start_y = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_printf(RED "Error\n" RESET "No valid starting position found\n");
	return (0);
}

// Free memory allocated for the visited array
void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

int	validate_and_replace_spaces(t_map *map)
{
	int	**visited;
	int	start_x;
	int	start_y;

	start_x = -1;
	start_y = -1;
	if (!find_start_position(map, &start_x, &start_y))
		return (0);
	if (!allocate_visited(&visited, map->map_height,
			ft_strlen(map->map_data[0])))
	{
		ft_printf(RED "Error\n" RESET
			"Memory allocation failed for DFS visited map\n");
		return (0);
	}
	if (!dfs_replace_spaces(map, start_x, start_y, visited))
		return (free_visited(visited, map->map_height), 0);
	free_visited(visited, map->map_height);
	return (1);
}
