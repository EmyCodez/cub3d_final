/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:07:17 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 00:57:06 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_ray_length(t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (ray->raydir_x == 0)
		ray->dx = 1e30;
	else
		ray->dx = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->dy = 1e30;
	else
		ray->dy = fabs(1 / ray->raydir_y);
}

static void	calculate_step_and_side(t_ray *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->dx;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->pos_x) * ray->dx;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->dy;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->pos_y) * ray->dy;
	}
}

static void	check_wall_hit_dda(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->dx;
			ray->map_x += ray->step_x;
			ray->cur_side = 0;
		}
		else
		{
			ray->side_y += ray->dy;
			ray->map_y += ray->step_y;
			ray->cur_side = 1;
		}
		if (map->map_data[ray->map_x][ray->map_y] == '1')
			hit = 1;
	}
	if (ray->cur_side == 0)
		ray->wall_dist = (ray->side_x - ray->dx);
	else
		ray->wall_dist = (ray->side_y - ray->dy);
}

void	calculate_wall_distance(t_map *map, t_ray *ray, t_player *player)
{
	calculate_step_and_side(ray, player);
	check_wall_hit_dda(ray, map);
}
