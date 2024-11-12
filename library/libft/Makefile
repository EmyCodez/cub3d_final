# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 09:22:21 by esimpson          #+#    #+#              #
#    Updated: 2024/11/12 18:28:50 by esimpson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_bzero.c \
                ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c \
                 ft_strrchr.c ft_strncmp.c ft_strlen.c \
                 ft_strlcpy.c ft_strlcat.c ft_strchr.c  \
                 ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
                 ft_memmove.c ft_strdup.c ft_putnbr_fd.c ft_putstr_fd.c \
                 ft_putchar_fd.c ft_itoa.c ft_putendl_fd.c ft_substr.c \
                 ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
                 ft_split.c ft_atoi_base.c ft_countchar.c \
                 ft_lstadd_back.c ft_lstnew.c ft_matrixlen.c ft_free_ptr.c \
                 ft_newvector.c ft_free_2d_array.c

OBJ = $(SRC:%.c=%.o)

CFLAGS =  -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ) 
	
%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@    

clean:
	@rm -rf $(OBJ) 
    
fclean: clean
	@rm -rf $(NAME)

re: fclean all 

.PHONY: clean fclean all re 
