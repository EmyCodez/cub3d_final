/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:07:29 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/08 16:58:22 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	create_border_row(char **row, int width)
{
	*row = malloc(width + 3); // +1 for '\0', +2 for borders
	if (!*row)
		return ;
	ft_memset(*row, '1', width + 2);
	(*row)[width + 2] = '\0';
}

void	create_padded_row(char **new_row, char *old_row, int width)
{
	int	len;

	len = ft_strlen(old_row);
	*new_row = malloc(width + 3); // +1 for '\0', +2 for padding
	if (!*new_row)
		return ;
	ft_memset(*new_row, '1', width + 2);    // Initialize with '1's
	ft_strncpy(*new_row + 1, old_row, len); // Copy old data with padding
	(*new_row)[width + 1] = '1';            // Right padding with '1'
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

void	make_map_square(t_map *map)
{
	int		i;
	int		max_width;
	char	**new_map;
	int		len;

	i = 0;
	max_width = 0;
	while (i < map->map_height) // Find maximum width in map
	{
		len = ft_strlen(map->map_data[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	new_map = malloc(sizeof(char *) * (map->map_height + 2)); // +2 for borders
	create_border_row(&new_map[0], max_width);
	// Create top border
	i = 0;
	while (i < map->map_height) // Create padded rows with side borders
	{
		create_padded_row(&new_map[i + 1], map->map_data[i], max_width);
		i++;
	}
	create_border_row(&new_map[map->map_height + 1], max_width);
	// Bottom border
	free_old_map(map); // Free old map data
	map->map_data = new_map;
	map->map_height += 2; // Adjust height for added borders
}

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
			printf(RED "Error\n" RESET "Line %d is longer \n ", i + 1);
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
		printf(RED "Error\n" RESET "Map has invalid structure due to line length inconsistency.\n");
		return (0);
	}
	printf("Map structure is valid.\n");
	return (1);
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
				return (ft_printf(RED "Error\n" RESET "Invalid character '%c' in map\n",
									map->map_data[i][j]),
						0);
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
		return (ft_printf(RED "Error\n" RESET "%d start positions found \n",
							player_count),
				0);
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	// Check top and bottom rows (should only contain '1' and spaces)
	while (map->map_data[0][i] && map->map_data[map->map_height - 1][i])
	{
		if (map->map_data[0][i] != '1' && map->map_data[0][i] != ' ')
			return (ft_printf(RED "Error\n" RESET "Top boundary is not closed by walls\n"),
					0);
		if (map->map_data[map->map_height - 1][i] != '1'
			&& map->map_data[map->map_height - 1][i] != ' ')
			return (ft_printf(RED "Error\n" RESET "Bottom boundary is not closed by walls\n"),
					0);
		i++;
	}
	i = 0;
	while (map->map_data[i])
	{
		if (map->map_data[i][0] != '1' && map->map_data[i][0] != ' ')
			return (ft_printf(RED "Error\n" RESET "Left boundary is not closed by walls\n"),
					0);
		j = ft_strlen(map->map_data[i]) - 1;
		if (map->map_data[i][j] != '1' && map->map_data[i][j] != ' ')
			return (ft_printf(RED "Error\n" RESET "Right boundary is not closed by walls\n"),
					0);
		i++;
	}
	return (1);
}

int	map_checks(t_map *map)
{
	if (!check_valid_characters(map))
		return (0);
	ft_printf(GREEN "Character check Successfull\n" RESET);
	if (!check_player_position(map))
		return (0);
	ft_printf(GREEN "Player Position Check Successfull\n" RESET);
	if (!check_walls(map))
		return (0);
	make_map_square(map);
	if (!validate_map_structure(map))
		return (0);
	if (!validate_and_replace_spaces(map))
		return (0);
	ft_printf(GREEN "Map Wall Check Successfull\n" RESET);
	return (1);
}
