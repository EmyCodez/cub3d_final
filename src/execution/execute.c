/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:05:38 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 02:02:11 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	execute(t_data *data)
{
	data_init(data);
	raycast(data);
	mlx_hook(data->win_ptr, 2, 0, &on_keypress, data);
	mlx_hook(data->win_ptr, 3, 0, &on_keyrelease, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &exit_game, data);
	mlx_loop_hook(data->mlx_ptr, &hook_loop, data);
	mlx_loop(data->mlx_ptr);
	ft_free_2d_array(&data->map.map_data);
}
