/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:58:38 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/16 10:24:16 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	free_map(char ***map)
{
	size_t	i = 0;

	while ((*map)[i] != NULL) {
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

static char	*read_data(int fd)
{
	char	*content = NULL;
	char	buf[BUFFER_SIZE + 1] = {'\0'};
	int		read_size = 0;

	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0) {
		buf[read_size] = '\0';
		if (content == NULL) {
			content = ft_strdup(buf);
		} else {
			content = ft_strjoin(content, buf);
		}
	}
	return (content);
}

static int	do_bsq(int fd)
{
	char	*content = NULL;
	char	**map = NULL;
	t_info	*info;

	// Read data
	content = read_data(fd);
	if (content == NULL) {
		fatal_error("read_data();");
	}
	if (is_last_newline(content) == false) {
		free(content);
		map_error_exit(NOT_EXIST_LAST_NEWLINE);
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
	free_map(&map);
	free(info);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	if (argc < 2) {
		do_bsq(STDIN_FILENO);
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		int fd = open(argv[i], O_RDONLY);

		if (fd == -1) {
			return (FAIL);
		}
		do_bsq(fd);
		if ((i + 1) != argc) {
			ft_putchar_fd(STDOUT_FILENO, '\n');
		}
		close(fd);
	}
#ifdef LEAKS
	system("leaks -q bsq");
#endif
	return (0);
}
