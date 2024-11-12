/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:18:59 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/01 15:43:21 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_north(t_player *player)
{
	while (player->dir_x > 0.0 || player->dir_y > -1.0)
		rotate_left(player);
}

static void	set_west(t_player *player)
{
	while (player->dir_x > -1.0 || player->dir_y > 0.0)
		rotate_left(player);
}

static void	set_east(t_player *player)
{
	while (player->dir_x < 1.0 || player->dir_y > 0.0)
		rotate_right(player);
}

void	set_player_direction(t_player *player)
{
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = 0.66;
	player->plane_y = 0;
	if (player->direction == 'E')
		set_east(player);
	else if (player->direction == 'W')
		set_west(player);
	else if (player->direction == 'N')
		set_north(player);
}
