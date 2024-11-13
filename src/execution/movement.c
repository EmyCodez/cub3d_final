/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:31:35 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 00:57:16 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->player.pos_x + data->player.dir_x * 0.3;
	new_pos_y = data->player.pos_y + data->player.dir_y * 0.3;
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dir_x * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y += data->player.dir_y * 0.05;
}

void	move_backward(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->player.pos_x - data->player.dir_x * 0.3;
	new_pos_y = data->player.pos_y - data->player.dir_y * 0.3;
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dir_x * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dir_y * 0.05;
}

void	move_left(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(data->player.pos_x - data->player.dir_y * 0.3);
	new_pos_y = (int)(data->player.pos_y + data->player.dir_x * 0.3);
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dir_y * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y += data->player.dir_x * 0.05;
}

void	move_right(t_data *data)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = (int)(data->player.pos_x + data->player.dir_y * 0.3);
	new_pos_y = (int)(data->player.pos_y - data->player.dir_x * 0.3);
	if (data->map.map_data[new_pos_x][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dir_y * 0.05;
	if ((data->map.map_data[(int)data->player.pos_x][new_pos_y] != '1'))
		data->player.pos_y -= data->player.dir_x * 0.05;
}
