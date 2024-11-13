/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:57:15 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 00:57:21 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_player *player)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(ROTATE_SPEED) - player->dir_y
		* sin(ROTATE_SPEED);
	player->dir_y = olddir_x * sin(ROTATE_SPEED) + player->dir_y
		* cos(ROTATE_SPEED);
	oldplane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(ROTATE_SPEED) - player->plane_y
		* sin(ROTATE_SPEED);
	player->plane_y = oldplane_x * sin(ROTATE_SPEED) + player->plane_y
		* cos(ROTATE_SPEED);
}

void	rotate_right(t_player *player)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-ROTATE_SPEED) - player->dir_y
		* sin(-ROTATE_SPEED);
	player->dir_y = olddir_x * sin(-ROTATE_SPEED) + player->dir_y
		* cos(-ROTATE_SPEED);
	oldplane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(-ROTATE_SPEED) - player->plane_y
		* sin(-ROTATE_SPEED);
	player->plane_y = oldplane_x * sin(-ROTATE_SPEED) + player->plane_y
		* cos(-ROTATE_SPEED);
}
