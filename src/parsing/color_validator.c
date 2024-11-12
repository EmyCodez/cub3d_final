/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:56:37 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/08 16:53:35 by esimpson         ###   ########.fr       */
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
		free(arr[i]); // Free each individual string
		i++;
	}
	free(arr); // Free the array itself
}

static int	assign_rgb_values(char **hold_color_value, int *r, int *g, int *b)
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
	char	**hold_color_value;
	int		result;

	if (!map->ceiling_color_value)
		return (ft_printf(RED "Error\n" RESET "Ceiling color value is empty\n"),
				0);
	hold_color_value = ft_split(map->ceiling_color_value, ',');
	if (!hold_color_value)
		return (ft_printf(RED "Error\n" RESET "Failed to split the ceiling color value\n"),
				0);
	result = assign_rgb_values(hold_color_value, &map->c_red, &map->c_green,
			&map->c_blue);
	ft_free_split(hold_color_value);
	return (result);
}

static int	assign_the_floor_color(t_map *map)
{
	char	**hold_color_value;
	int		result;

	if (!map->floor_color_value)
		return (ft_printf(RED "Error\n" RESET "Floor color value is empty\n"),
				0);
	hold_color_value = ft_split(map->floor_color_value, ',');
	if (!hold_color_value)
		return (ft_printf(RED "Error\n" RESET "Failed to split the floor color value\n"),
				0);
	result = assign_rgb_values(hold_color_value, &map->f_red, &map->f_green,
			&map->f_blue);
	ft_free_split(hold_color_value);
	return (result);
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
		{
			map->floor_color_value = ft_strdup(line + 2);
			ft_printf("F-> %s\n", map->floor_color_value);
		}
		if (ft_strncmp(line, "C ", 2) == 0)
		{
			map->ceiling_color_value = ft_strdup(line + 2);
			ft_printf("C-> %s\n", map->ceiling_color_value);
		}
		line = get_next_line(fd);
	}
	ft_printf("\n");
	if (!assign_the_floor_color(map))
		return (0);
	ft_printf("\nFloor color assigned\n");
	if (!assign_the_ceiling_color(map))
		return (0);
	ft_printf("\nCeiling color assigned\n");
	ft_printf("f_red-> %d\n", map->f_red);
	ft_printf("f_green-> %d\n", map->f_green);
	ft_printf("f_blue-> %d\n", map->f_blue);
	ft_printf("c_red-> %d\n", map->c_red);
	ft_printf("c_green-> %d\n", map->c_green);
	ft_printf("c_blue-> %d\n", map->c_blue);
	return (1);
}



