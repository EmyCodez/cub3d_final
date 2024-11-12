/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:25:09 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:26:47 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		ft_printf("%s\n", map->map_data[i]);
		i++;
	}
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
