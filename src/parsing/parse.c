/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:25:09 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/12 23:49:20 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		printf("%s\n", map->map_data[i]);
		i++;
	}
}

int	map_checks(t_map *map)
{
	if (!check_valid_characters(map))
		return (0);
	ft_printf(GREEN"Character check Successfull\n"RESET);
	if (!check_player_position(map))
		return (0);
	ft_printf(GREEN"Player Position Check Successfull\n"RESET);
	if (!check_walls(map))
		return (0);
	make_map_square(map);
	if (!validate_map_structure(map))
		return (0);
	if (!validate_and_replace_spaces(map))
		return (0);
	ft_printf(GREEN"Map Wall Check Successfull\n"RESET);
	return (1);
}

void	parse_input(char *path, t_map *map)
{
	struct_initialization(map);
	if (!validate_file_extention(path))
		exit(EXIT_FAILURE);
	if (!validate_texture(path, map))
		exit(EXIT_FAILURE);
	if (!validate_color(path, map))
		exit(EXIT_FAILURE);
	if (!map_validator(path, map))
		exit(EXIT_FAILURE);
	if (!map_checks(map))
		exit(EXIT_FAILURE);
	print_map(map);
}
