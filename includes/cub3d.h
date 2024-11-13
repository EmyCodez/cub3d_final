/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:08:07 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/13 10:02:10 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 720
# define WIN_HEIGHT 560
# define ROTATE_SPEED 0.05

/* ------------------------------- INCLUDES --------------------------------- */

# include "../library/get_next_line/get_next_line.h"
# include "../library/libft/libft.h"
# include "../library/libftprintf/ft_printf.h"
# include "../library/mlx/mlx.h"
# include "keys.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

# define COLOUR_EXCEED_VALUE 255

/* ----------------------------- DATA STRUCTURES --------------------------- */

typedef struct s_map
{
	char		**map_data;
	char		**map_data_cpy;
	int			map_height;
	int			map_width;
	int			player_cnt;
	int			f_red;
	int			f_green;
	int			f_blue;
	int			c_red;
	int			c_green;
	int			c_blue;
	char		*no_texture_path;
	char		*so_texture_path;
	char		*ea_texture_path;
	char		*we_texture_path;
	char		**hold_color_value;
	char		*ceiling_color_value;
	char		*floor_color_value;
}				t_map;

typedef struct s_image
{
	void		*img;
	char		*address;
	int			bits_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_key
{
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		left;
	bool		right;
}				t_key;

typedef struct s_line
{
	int			wall_height;
	int			wall_start;
	int			wall_end;
	int			x;
	int			y;
	int			y_start;
	int			y_end;
	int			texture_x;
	int			texture_y;
}				t_line;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_x;
	double		side_y;
	int			step_x;
	int			step_y;
	int			cur_side;
	double		dx;
	double		dy;
	double		wall_dist;
}				t_ray;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	char		direction;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_key		key;
	t_ray		ray;
	t_player	player;
	t_image		win_img;
	t_line		line;
	t_image		north_texture;
	t_image		south_texture;
	t_image		west_texture;
	t_image		east_texture;
	int			floor_color;
	int			ceiling_color;
}				t_data;

/* --------------------------- FUNCTION PROTOTYPES ------------------------- */

/* ************************************************************************** */
/*                              FILENAME: parse.c                             */
/* ************************************************************************** */

void			print_map(t_map *map);
void			parse_input(char *path, t_map *map);
int				map_checks(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: struct_init.c                       */
/* ************************************************************************** */

void			struct_initialization(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: extention_check.c                   */
/* ************************************************************************** */

int				validate_file_extention(char *str);

/* ************************************************************************** */
/*                              FILENAME: texture_validator.c                 */
/* ************************************************************************** */

int				validate_texture(char *path, t_map *map);
int				check_texture_identifiers_is_present(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: color_validator.c                   */
/* ************************************************************************** */

int				validate_color(char *path, t_map *map);

/* ************************************************************************** */
/*                              FILENAME: map_validator.c                     */
/* ************************************************************************** */

int				map_validator(char *path, t_map *map);

/* ************************************************************************** */
/*                              FILENAME: map_validator2.c                    */
/* ************************************************************************** */

int				is_map_line(char *line);
void			free_map_data(t_map *map, int line_count);

/* ************************************************************************** */
/*                              FILENAME: map_checks.c                        */
/* ************************************************************************** */

char			*ft_strncpy(char *dest, const char *src, size_t n);
void			create_border_row(char **row, int width);
void			create_padded_row(char **new_row, char *old_row, int width);
void			free_old_map(t_map *map);
int				check_valid_characters(t_map *map);
int				check_player_position(t_map *map);
int				validate_and_replace_spaces(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: map_checks2.c                       */
/* ************************************************************************** */

int				check_line_lengths(t_map *map);
int				validate_map_structure(t_map *map);
void			make_map_square(t_map *map);
int				check_walls(t_map *map);

/* ************************************************************************** */
/*                              FILENAME: init_data.c                         */
/* ************************************************************************** */
void			data_init(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: init_player.c                       */
/* ************************************************************************** */
void			init_player(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: player_direction.c                  */
/* ************************************************************************** */
void			set_player_direction(t_player *player);

/* ************************************************************************** */
/*                              FILENAME: rotate.c                            */
/* ************************************************************************** */
void			rotate_left(t_player *player);
void			rotate_right(t_player *player);

/* ************************************************************************** */
/*                              FILENAME: execute.c                           */
/* ************************************************************************** */
void			execute(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: calculate.c                         */
/* ************************************************************************** */
void			set_ray_length(t_ray *ray, t_player *player);
void			calculate_wall_distance(t_map *map, t_ray *ray,
					t_player *player);

/* ************************************************************************** */
/*                              FILENAME: movement.c                          */
/* ************************************************************************** */
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: hooks.c                             */
/* ************************************************************************** */
int				on_keyrelease(int key, t_data *data);
int				hook_loop(t_data *data);
int				on_keypress(int key, t_data *data);
int				exit_game(t_data *data);

/* ************************************************************************** */
/*                              FILENAME: texture.c                           */
/* ************************************************************************** */
void			load_texture(t_data *data, t_image *image, char *path);
void			paint_texture_line(t_data *data, t_ray *ray, t_line *line,
					double wall_x);

/* ************************************************************************** */
/*                              FILENAME: raycast.c                           */
/* ************************************************************************** */
void			raycast(t_data *data);

#endif
