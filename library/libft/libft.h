/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:11:36 by esimpson          #+#    #+#             */
/*   Updated: 2024/11/09 15:31:23 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* First Part */

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

/* Additional Functions */

char				*ft_itoa(int num);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
int					ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int num, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_atoi_base(const char *str, int str_base);

/* Free pointer and set to NULL */
void				ft_free_ptr(void **ptr);

/* Implementation of linked list */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* Creates new node allocating with malloc */
t_list				*ft_lstnew(void *content);

/* Adds new node at the end of the linked list */
void				ft_lstadd_back(t_list **lst, t_list *newnode);

/* Vector with x and y coordinates */
typedef struct s_vector
{
	int				x;
	int				y;
}					t_vector;

/* Returns length of a matrix (char **) */
int					ft_matrixlen(char **m);

/* Frees all allocated memory from a 2D array */
void				ft_free_2d_array(char ***map);

/* Creates a new t_vector with the given x and y parameters */
t_vector			ft_newvector(int x, int y);

/* Compares ends of two strings up to the n-th character */
int					ft_strrncmp(const char *s1, const char *s2, size_t n);

/* Returns number of matching chars in a string */
int					ft_countchar(char *s, char c);

#endif