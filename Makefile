# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:31:19 by esimpson          #+#    #+#              #
#    Updated: 2024/11/08 13:49:44 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = ./library/mlx
LIBFT_PATH = ./library/libft
LIBFT_PRINTF_PATH = ./library/libftprintf
GNL_PATH = ./library/get_next_line
SRC_PATH = ./src
EXEC_PATH = ./src/execution
PARSE_PATH = ./src/parsing

MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -lm

MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_PRINTF = $(LIBFT_PRINTF_PATH)/libftprintf.a
GNL = $(GNL_PATH)/get_next_line.a

SRC_FILES =	$(SRC_PATH)/main.c \
			$(PARSE_PATH)/parse.c $(PARSE_PATH)/extension_check.c $(PARSE_PATH)/struct_init.c \
            $(PARSE_PATH)/texture_validator.c $(PARSE_PATH)/texture_validator2.c $(PARSE_PATH)/dfs.c \
			$(PARSE_PATH)/color_validator.c $(PARSE_PATH)/map_validator.c $(PARSE_PATH)/map_checks.c \
			$(EXEC_PATH)/execute.c  $(EXEC_PATH)/data_init.c $(EXEC_PATH)/init_player.c \
			$(EXEC_PATH)/player_direction.c $(EXEC_PATH)/rotate.c $(EXEC_PATH)/calculate.c \
			$(EXEC_PATH)/raycast.c $(EXEC_PATH)/movement.c $(EXEC_PATH)/hooks.c $(EXEC_PATH)/texture.c
				 			 
SRC_OBJ = $(SRC_FILES:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(SRC_OBJ) 
	@make -C $(MLX_PATH) all
	@make -C $(LIBFT_PATH) all
	@make -C $(LIBFT_PRINTF_PATH) all
	@make -C $(GNL_PATH) all
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(MLX_FLAGS) $(LIBFT) $(LIBFT_PRINTF) $(GNL) $(MLX) -o $(NAME)
	@echo "SUCCESSFULLY MADE $(words $(SRC_OBJ)) object files"

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBFT_PRINTF_PATH) clean
	@make -C $(GNL_PATH) clean
	@rm -f $(SRC_OBJ) 

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBFT_PRINTF_PATH) fclean
	@make -C $(GNL_PATH) fclean
	@make -C $(MLX_PATH) clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re 