/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:18:44 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:27:16 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	dfs_replace_spaces(t_map *map, int x, int y, int **visited)
{
	// Base cases: Check if out of bounds
	if (x < 0 || y < 0 || x >= map->map_height
		|| y >= (int)strlen(map->map_data[x]))
	{
		// Out of bounds, nothing to do
		return (1);
	}
	// Check if this position has been visited
	if (visited[x][y])
		return (1);
	// Mark the current cell as visited
	visited[x][y] = 1;
	// If we find a space, we replace it with '0'
	if (map->map_data[x][y] == ' ')
	{
		ft_printf("Replacing space at (%d, %d) with '0'\n", x + 1, y + 1);
		map->map_data[x][y] = '1';
	}
	// Explore neighbors: Up, Down, Left, Right
	if (!dfs_replace_spaces(map, x + 1, y, visited))
		return (0); // Down
	if (!dfs_replace_spaces(map, x - 1, y, visited))
		return (0); // Up
	if (!dfs_replace_spaces(map, x, y + 1, visited))
		return (0); // Right
	if (!dfs_replace_spaces(map, x, y - 1, visited))
		return (0); // Left
	return (1);     // Successfully checked this path
}

int	allocate_visited(int ***visited, int height, int width)
{
	int	i;

	*visited = malloc(sizeof(int *) * height);
	if (!*visited)
		return (0);
	i = 0; // Initialize the loop counter
	while (i < height)
	{
		(*visited)[i] = malloc(sizeof(int) * width);
		if (!(*visited)[i])
			return (0);
		memset((*visited)[i], 0, sizeof(int) * width);
		// Initialize to zero (unvisited)
		i++;
		// Increment the loop counter
	}
	return (1);
}

int	validate_and_replace_spaces(t_map *map)
{
	int **visited;
	int start_x = -1, start_y = -1;

	// Find the first valid starting point (0, N, S, E, W)
	int i = 0; // Initialize loop variable
	while (i < map->map_height)
	{
		size_t j = 0; // Loop variable for inner loop
		while (j < strlen(map->map_data[i]))
		{
			if (strchr("0NSEW", map->map_data[i][j]))
			{
				start_x = i;
				start_y = j;
				break ; // Found a starting position
			}
			j++; // Increment inner loop variable
		}
		if (start_x != -1)
			break ; // Exit if starting position is found
		i++;       // Increment outer loop variable
	}

	// Check if no valid starting position was found
	if (start_x == -1)
	{
		ft_printf(RED "Error\n" RESET "No valid starting position found\n");
		return (0);
	}

	// Allocate memory for visited
	if (!allocate_visited(&visited, map->map_height, strlen(map->map_data[0])))
	{
		ft_printf(RED "Error\n" RESET "Memory allocation failed for DFS visited map\n");
		return (0);
	}

	// Perform DFS from the starting position to check for spaces and replace them
	if (!dfs_replace_spaces(map, start_x, start_y, visited))
	{
		for (int i = 0; i < map->map_height; i++)
			free(visited[i]);
		free(visited);
		return (0); // DFS detected an issue
	}

	// Cleanup visited array
	for (int i = 0; i < map->map_height; i++)
		free(visited[i]);
	free(visited);

	return (1); // Validation passed, spaces replaced
}