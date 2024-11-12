/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:42:08 by adhil             #+#    #+#             */
/*   Updated: 2024/10/22 13:15:15 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// GNL

char	*get_next_line(int fd);

// GNL_utilities

char	*get_next_line(int fd);
char	*read_to_remaining(int fd, char *remaining);
char	*assign_to_return_line(char *remaining);
char	*clear_stuffs_from_remaining(char *remaining);
char	*finalize_the_output_for_so_long(char *str);
char	*ft_strjoin_g(char *s1, char *s2);
size_t	ftstrleng(const char *s);
char	*ft_strchr_g(const char *s, int c);


#endif