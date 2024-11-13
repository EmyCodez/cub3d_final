/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:00:50 by adshafee          #+#    #+#             */
/*   Updated: 2024/11/12 23:46:51 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_my_map_is_okay(char *str)
{
	int		fd;
	size_t	read_bytes;
	char	buf[1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(RED"(ERROR) File not found....!"RESET);
		return (0);
	}
	read_bytes = read(fd, buf, 1);
	if (read_bytes == 0)
	{
		ft_printf(RED"(ERROR) No contents in File....!"RESET);
		return (0);
		close(fd);
	}
	close(fd);
	return (1);
}

static int	extention_check(char *str)
{
	if (str[0] == '.' && str[1] == 'c' && str[2] == 'u'
		&& str[3] == 'b' && str[4] == '\0')
	{
		ft_printf(RED"(ERROR) File name is invalid...!"RESET);
		return (0);
	}
	if (str[0] == '\0')
	{
		ft_printf(RED"(ERROR) File name cannot be empty\n"RESET);
		return (0);
	}
	if (!is_my_map_is_okay(str))
		return (0);
	return (1);
}

int	validate_file_extention(char *str)
{
	char	*main_extention;
	int		i;
	int		j;

	i = 0;
	j = 4;
	main_extention = ".cub";
	while (str[i])
		i++;
	i--;
	j--;
	while (j >= 0)
	{
		if (str[i] != main_extention[j])
		{
			ft_printf(RED"(ERROR) Wrong file extention....!"RESET);
			return (0);
		}
		i--;
		j--;
	}
	if (!extention_check(str))
		return (0);
	return (1);
}
