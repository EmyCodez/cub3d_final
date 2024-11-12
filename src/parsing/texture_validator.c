/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:20:19 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/08 16:51:30 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	assign_texture_files(char *path, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED "(ERROR) Unable to open the Texture file..!\n" RESET);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			map->no_texture_path = ft_strdup(line + 3);
			ft_printf("%s\n", map->no_texture_path);
		}
		if (ft_strncmp(line, "SO ", 3) == 0)
		{
			map->so_texture_path = ft_strdup(line + 3);
			ft_printf("%s\n", map->so_texture_path);
		}
		if (ft_strncmp(line, "EA ", 3) == 0)
		{
			map->ea_texture_path = ft_strdup(line + 3);
			ft_printf("%s\n", map->ea_texture_path);
		}
		if (ft_strncmp(line, "WE ", 3) == 0)
		{
			map->we_texture_path = ft_strdup(line + 3);
			ft_printf("%s\n", map->we_texture_path);
		}
		line = get_next_line(fd);
	}
	if (!check_texture_identifiers_is_present(map))
		exit(1);
	free(line);
}

static int	extention_check_three(char *str)
{
	int		fd;
	size_t	read_bytes;
	char	buf[1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED "(ERROR) Texture File not found....!\n" RESET);
		return (0);
	}
	read_bytes = read(fd, buf, 1);
	if (read_bytes == 0)
	{
		ft_printf(RED "(ERROR) No contents in Texture File..! -> " RESET);
		return (0);
		close(fd);
	}
	close(fd);
	return (1);
}

static int	extention_check_two(char *str)
{
	if (str[0] == '.' && str[1] == 'x' && str[2] == 'p' && str[3] == 'm'
		&& str[4] == '\0')
	{
		ft_printf(RED "(ERROR) Texture File name is invalid...!\n" RESET);
		return (0);
	}
	if (str[0] == '\0')
	{
		ft_printf(RED "(ERROR) Texture File name cannot be empty\n" RESET);
		return (0);
	}
	if (!extention_check_three(str))
		return (0);
	return (1);
}

static int	texture_extention_check(char *str, int *error)
{
	char	*main_extention;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (ft_printf(RED "Issue Bro\n" RESET), (*error)++, 0);
	j = 4;
	main_extention = ".xpm";
	while (str[i])
		i++;
	i--;
	j--;
	while (j >= 0)
	{
		if (str[i] != main_extention[j])
		{
			ft_printf(RED "(ERROR) Wrong Texture file extention...!\n" RESET);
			return ((*error)++, 0);
		}
		i--;
		j--;
	}
	if (!extention_check_two(str))
		return ((*error)++, 0);
	return (1);
}

int	validate_texture(char *path, t_map *map)
{
	int	error_count;

	error_count = 0;
	assign_texture_files(path, map);
	if (!texture_extention_check(map->no_texture_path, &error_count))
		ft_printf(RED "No Content in North Texture file\n" RESET);
	if (!texture_extention_check(map->so_texture_path, &error_count))
		ft_printf(RED "No Content in South Texture file\n" RESET);
	if (!texture_extention_check(map->ea_texture_path, &error_count))
		ft_printf(RED "No Content in East Texture file\n" RESET);
	if (!texture_extention_check(map->we_texture_path, &error_count))
		ft_printf(RED "No Content in West Texture file\n" RESET);
	if (error_count > 0)
	{
		ft_printf("Total errors: %d\n", error_count);
		return (0);
	}
	return (1);
}
