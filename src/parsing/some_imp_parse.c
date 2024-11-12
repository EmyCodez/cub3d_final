
#include "../../includes/cub3d.h"

bool	player_symbol(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

void	free_malloced(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_height)
		free(map->map_data[i++]);
	if (map->map_height)
		free(map->map_data);
}

void	put_error(const char *error, t_map *map)
{
	write(2, "ERROR\n", ft_strlen("ERROR\n"));
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	free_malloced(map);
	exit(1);
}

bool	defined_symbol(char c)
{
	if (c == '0' || c == '1' || c == ' ' || player_symbol(c) || c == 'D')
		return (true);
	return (false);
}

void	valid_player(t_map *map)
{
	if (map->player_cnt > 1)
		put_error("Multiplayer!", map);
	if (map->player_cnt == 0)
		put_error("No Player!", map);
}

static void	is_closed(t_map *m, int y, int x)
{
	if (y == 0 || m->map_data[y - 1][x] == ' ')
		put_error("Map must be closed", m);
	if (!m->map_data[y + 1] || m->map_data[y + 1][x] == ' ')
		put_error("Map must be closed", m);
	if (x == 0 || m->map_data[y][x - 1] == ' ')
		put_error("Map must be closed", m);
	if (m->map_data[y][x + 1] == ' ' || !m->map_data[y][x + 1])
		put_error("Map must be closed", m);
}

static bool	is_walled(t_map *m, int y, int x)
{
	if (y == 0 || !m->map_data[y + 1] || !m->map_data[y][x + 1])
		put_error("Doors must be walled", m);
	if (m->map_data[y][x + 1] == '1' && m->map_data[y][x - 1] == '1' &&
		m->map_data[y + 1][x] == '1' && m->map_data[y - 1][x] == '1')
		return (false);
	if (m->map_data[y][x + 1] == '1')
		if (m->map_data[y][x - 1] == '1')
			return (true);
	if (m->map_data[y + 1][x] == '1')
		if (m->map_data[y - 1][x] == '1')
			return (true);
	return (false);
}

void	check_empty_line(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->map_height)
	{
		x = 0;
		while (map->map_data[y][x] == ' ' || map->map_data[y][x] == '\t')
			x++;
		if (!map->map_data[y][x])
			put_error("Empty Line", map);
	}
}

void	check_valid_map(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->map_height)
	{
		x = -1;
		while (++x < map->map_width)
		{
			if (defined_symbol(map->map_data[y][x]))
			{
				if (player_symbol(map->map_data[y][x]))
					map->player_cnt++;
				if (map->map_data[y][x] == '0'
					|| player_symbol(map->map_data[y][x]))
					is_closed(map, y, x);
				if (map->map_data[y][x] == 'D')
					if (!is_walled(map, y, x))
						put_error("Must be walled", map);
			}
		}
	}
}
