/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:56:37 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/13 05:13:54 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	assign_rgb_values(char	**hold_color_value, int *r, int *g, int *b)
{
	int	color;

	if (!hold_color_value[0] || !hold_color_value[1] || !hold_color_value[2])
		return (ft_printf(RED "Error\n" RESET "Incomplete RGB values\n"), 0);
	color = ft_atoi(hold_color_value[0]);
	if (color > COLOUR_EXCEED_VALUE)
		return (ft_printf(RED "Error\n" RESET "Color value exceeds 255\n"), 0);
	*r = color;
	color = ft_atoi(hold_color_value[1]);
	if (color > COLOUR_EXCEED_VALUE)
		return (ft_printf(RED "Error\n" RESET "Color value exceeds 255\n"), 0);
	*g = color;
	color = ft_atoi(hold_color_value[2]);
	if (color > COLOUR_EXCEED_VALUE)
		return (ft_printf(RED "Error\n" RESET "Color value exceeds 255\n"), 0);
	*b = color;
	return (1);
}

static int	assign_the_ceiling_color(t_map *map)
{
	char	**clr_value;
	int		r;

	if (!map->ceiling_color_value)
	{
		ft_printf(RED"Error\n"RESET"Ceiling color value is empty\n");
		return (0);
	}
	clr_value = ft_split(map->ceiling_color_value, ',');
	if (!clr_value)
	{
		ft_printf(RED"Error\nError Splitting ceiling color value\n"RESET);
		return (0);
	}
	r = assign_rgb_values(clr_value, &map->c_red, &map->c_green, &map->c_blue);
	ft_free_split(clr_value);
	return (r);
}

static int	assign_the_floor_color(t_map *map)
{
	char	**clr_value;
	int		r;

	if (!map->floor_color_value)
		return (ft_printf(RED"Error\n"RESET"Floor color value is empty\n"), 0);
	clr_value = ft_split(map->floor_color_value, ',');
	if (!clr_value)
	{
		ft_printf(RED"Error\nFailed to split the floor color value\n"RESET);
		return (0);
	}
	r = assign_rgb_values(clr_value, &map->f_red, &map->f_green, &map->f_blue);
	ft_free_split(clr_value);
	return (r);
}

int	validate_color(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf(RED "Error\n" RESET "Failed to open file\n"), 0);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			map->floor_color_value = ft_strdup(line + 2);
		if (ft_strncmp(line, "C ", 2) == 0)
			map->ceiling_color_value = ft_strdup(line + 2);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!assign_the_floor_color(map))
		return (0);
	if (!assign_the_ceiling_color(map))
		return (0);
	return (1);
}
