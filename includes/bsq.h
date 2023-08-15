/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/15 23:01:59 by hnoguchi         ###   ########.fr       */
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

# define FT_BUFSIZ 320000
# define IN 1
# define OUT 0
# define SUCCESS 1
# define FAIL 0
# define ERROR_PREFIX "map error: "
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
size_t			ft_strlen(const char *str);
void			ft_putchar_fd(int fd, char c);
void			ft_putstr_fd(int fd, const char *str);
int				ft_is_printable(char c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
char			**ft_split(char *str, char *charset);
int				ft_atoi(char *str);
int				ft_validate_5(char **map);
t_info			*ft_prse(char **map);
int				ft_validate_map(char **map, t_info *info);
bool			ft_is_last_newline(char *content);
void			set_tempcrs(t_tempcrs *p_tempcrs);
int				ft_check_1(char **map, int col, int row, t_info *p_info);
void			ft_make_map(char **map, t_info *p_info);
void			set_bsq(t_bsq *p_bsq);
int				ft_map_colsize(char **map);
void			error_exit(t_error_kind type);

#endif
