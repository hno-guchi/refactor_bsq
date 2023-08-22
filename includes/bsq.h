/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/22 10:42:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <libgen.h>

# define BUFFER_SIZE 320000
# define IN 1
# define OUT 0
# define SUCCESS 1
# define FAIL 0
# define ERROR_PREFIX "map error: "
# define FATAL_ERROR_PREFIX "fatal error: "
# define ERROR_NOT_EXIST_NEWLINE "Not exist newline."

typedef enum s_error_kind	t_error_kind;

enum	s_error_kind {
	NOT_EXIST_LAST_NEWLINE
};

typedef	struct	s_bsq
{
	int			x;
	int			y;
	int			size;
}				t_bsq;

typedef	struct	s_info
{
	int		num_rows;
	char	empty;
	char	obstacle;
	char	full;
}				t_info;

typedef	struct	s_tempcrs
{
	int	col;
	int	row;
	int	size;
}				t_tempcrs;

int				g_max;
int				g_col;
int				g_row;

// libft
int				ft_isspace(char c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *str);
void			ft_putchar_fd(int fd, char c);
void			ft_putstr_fd(int fd, const char *str);
int				ft_is_printable(char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_atoi(char *str);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

// bsq
int				ft_validate_5(char **map);
t_info			*ft_prse(char **map);
int				ft_validate_map(char **map, t_info *info);
bool			is_last_newline(const char *content);
void			set_tempcrs(t_tempcrs *p_tempcrs);
int				ft_check_1(char **map, int col, int row, t_info *p_info);
void			ft_make_map(char **map, t_info *p_info);
void			set_bsq(t_bsq *p_bsq);
int				ft_map_colsize(char **map);

// error.c
void			map_error_exit(t_error_kind type);
void			fatal_error(const char *location);

#endif
