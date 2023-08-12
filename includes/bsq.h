/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <louisnop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:30:46 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 14:44:42 by hnoguchi         ###   ########.fr       */
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
# define ERROR_PREFIX "map error\n"
# define ERROR_NOT_EXIST_NEWLINE "map error: Not exist newline\n"

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
int				ft_strlen(const char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
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

#endif
