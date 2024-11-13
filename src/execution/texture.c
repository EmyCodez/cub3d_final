/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:24:56 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 10:03:45 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	copy_texture_pixel(t_image *image, t_image *texture, t_line *line)
{
	int		color;
	char	*dst;
	char	*src;

	src = texture->address + (line->texture_y * texture->line_length
			+ line->texture_x * (texture->bits_pixel / 8));
	dst = image->address + (line->y * image->line_length + line->x
			* (image->bits_pixel / 8));
	color = *(unsigned int *)src;
	*(unsigned int *)dst = color;
}

static t_image	*check_texture_side(t_ray *ray, t_data *data)
{
	if (ray->cur_side == 0 && ray->raydir_x > 0)
		return (&data->east_texture);
	if (ray->cur_side == 0 && ray->raydir_x < 0)
		return (&data->west_texture);
	if (ray->cur_side == 1 && ray->raydir_y > 0)
		return (&data->south_texture);
	return (&data->north_texture);
}

void	paint_texture_line(t_data *data, t_ray *ray, t_line *line,
		double wall_x)
{
	int		y_max;
	double	step;
	double	tex_pos;
	t_image	*texture;

	texture = check_texture_side(ray, data);
	line->y = line->y_start;
	y_max = line->y_end;
	line->texture_x = (int)(wall_x * (double)texture->width);
	if (ray->cur_side == 0 && ray->raydir_x > 0)
		line->texture_x = texture->width - line->texture_x - 1;
	if (ray->cur_side == 1 && ray->raydir_y < 0)
		line->texture_x = texture->width - line->texture_x - 1;
	step = 1.0 * texture->height / line->wall_height;
	tex_pos = (line->wall_start - WIN_HEIGHT / 2 + line->wall_height / 2)
		* step;
	while (line->y < y_max)
	{
		line->texture_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		copy_texture_pixel(&data->win_img, texture, line);
		line->y++;
	}
}

void	load_texture(t_data *data, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &image->width,
			&image->height);
	if (image->img == NULL)
	{
		ft_printf("Error\nWall could not be loaded\n");
		exit_game(data);
	}
	image->address = mlx_get_data_addr(image->img, &image->bits_pixel,
			&image->line_length, &image->endian);
}
