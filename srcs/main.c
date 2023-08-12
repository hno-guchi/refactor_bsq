/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/12 14:39:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_map(char ***map)
{
	long int i;

	i = 0;
	while ((*map)[i]) {
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

char	*ft_read_data(int ifd)
{
	char	*content;
	char	buf[FT_BUFSIZ + 1];
	int		n;

	content = NULL;
	while ((n = read(ifd, buf, FT_BUFSIZ)) > 0) {
		buf[n] = '\0';
		if (content == NULL) {
			content = ft_strdup(buf);
		} else {
			content = ft_strjoin(content, buf);
		}
	}
	return (content);
}

typedef enum s_error_kind	t_error_kind;

enum	s_error_kind {
	NOT_EXIST_LAST_NEWLINE
};

void	error_exit(t_error_kind type) {
	switch(type) {
		case NOT_EXIST_LAST_NEWLINE:
			ft_puterror(FT_ERR_MAP);
			break;
		default:
			break;
	};
	exit(1);
}

int		ft_main(int fd)
{
	char	*content;
	char	**map;
	t_info	*info;

	// Read data
	content = ft_read_data(fd);
	if (ft_is_last_newline(content) == false) {
		free(content);
		error_exit(NOT_LAST_NEWLINE);
		// return (FAIL);
	}

	// Create map
	map = ft_split(content, "\n");
	free(content);
	if (ft_validate_5(map) == FAIL) {
		return (FAIL);
	}
	if (!(info = ft_prse(map))) {
		return (FAIL);
	}
	if (ft_validate_map(map, info) == FAIL) {
		return (FAIL);
	}

	// Do bsq, Print
	ft_make_map(map, info);
	ft_free_map(&map);
	free(info);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	if (argc < 2) {
		ft_main(STDIN_FILENO);
		// if (ft_main(STDIN_FILENO) == FAIL) {
		// 	ft_puterror(FT_ERR_MAP);
		// }
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);

		if (fd == -1) {
			return (FAIL);
		}
		if (ft_main(fd) == FAIL) {
			ft_puterror(FT_ERR_MAP);
		}
		if ((i + 1) != argc) {
			ft_putstr("\n");
		}
		close(fd);
	}
#ifdef LEAKS
	system("leaks -q bsq");
#endif
	return (0);
}
