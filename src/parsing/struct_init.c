/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:51:02 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:27:58 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	struct_initialization(t_map *map)
{
	map->map_data = NULL;
	map->map_data_cpy = NULL;
	map->player_cnt = 0;
	map->map_width = 0;
	map->map_height = 0;
	map->f_red = 0;
	map->f_green = 0;
	map->f_blue = 0;
	map->c_red = 0;
	map->c_green = 0;
	map->c_blue = 0;
	map->no_texture_path = NULL;
	map->so_texture_path = NULL;
	map->ea_texture_path = NULL;
	map->we_texture_path = NULL;
	map->hold_color_value = NULL;
	map->ceiling_color_value = NULL;
	map->floor_color_value = NULL;
}
