/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validator2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:41:24 by adshafee          #+#    #+#             */
/*   Updated: 2024/10/24 13:28:16 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture_identifiers_is_present(t_map *map)
{
	int	all_present;

	all_present = 1;
	if (map->no_texture_path == NULL)
	{
		ft_printf(RED "ERROR: North Identifier (NO) is missing.\n" RESET);
		all_present = 0;
	}
	if (map->so_texture_path == NULL)
	{
		ft_printf(RED "ERROR: South Identifier (SO) is missing.\n" RESET);
		all_present = 0;
	}
	if (map->we_texture_path == NULL)
	{
		ft_printf(RED "ERROR: West Identifier (WE) is missing.\n" RESET);
		all_present = 0;
	}
	if (map->ea_texture_path == NULL)
	{
		ft_printf(RED "ERROR: East Identifier (EA) is missing.\n" RESET);
		all_present = 0;
	}
	return (all_present);
}
