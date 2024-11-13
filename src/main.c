/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:10:52 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 10:04:18 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_old_maps(t_map *map)
{
	if (map->no_texture_path)
		free(map->no_texture_path);
	if (map->so_texture_path)
		free(map->so_texture_path);
	if (map->ea_texture_path)
		free(map->ea_texture_path);
	if (map->we_texture_path)
		free(map->we_texture_path);
	if (map->floor_color_value)
		free(map->floor_color_value);
	if (map->ceiling_color_value)
		free(map->ceiling_color_value);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 2)
	{
		printf(RED "(ERROR) Input 2 arguments\n" RESET);
		exit(EXIT_FAILURE);
	}
	parse_input(av[1], &data.map);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	data.win_img.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.win_img.address = mlx_get_data_addr(data.win_img.img,
			&data.win_img.bits_pixel,
			&data.win_img.line_length,
			&data.win_img.endian);
	execute(&data);
	free_old_maps(&data.map);
	return (0);
}
