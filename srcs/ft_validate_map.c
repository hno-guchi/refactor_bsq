/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:48:35 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/18 16:40:15 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

bool	ft_is_map_character(char c, t_info *info) {
	if (c != info->empty && c != info->obstacle) {
		return (false);
	}
	return (true);
}

bool		ft_is_map_elements(char **map, t_info *info)
{
	int i;
	int j;

	i = 1;
	while (map[i]) {
		j = 0;
		while (map[i][j]) {
			if (ft_is_map_character(map[i][j], info) == false) {
				return (false);
			}
			j += 1;
		}
		i += 1;
	}
	return (true);
}

bool	ft_is_same_length_of_lines(char **map, t_info *info)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map[i]);
	while (map[i]) {
		if (len != ft_strlen(map[i])) {
			return (false);
		}
		i++;
	}
	if (i - 1 != info->num_rows) {
		return (false);
	}
	return (true);
}

bool	is_last_newline(const char *content)
{
	if (content == NULL) {
		return (false);
	}
	int		i;

	i = 0;
	while (content[i] != '\0') {
		i++;
	}
	if (content[i - 1] != '\n') {
		return (false);
	}
	return (true);
}

int		ft_validate_map(char **map, t_info *info)
{
	if (map[0] == NULL || map[1] == NULL) {
		return (FAIL);
	}
	if (ft_is_map_elements(map, info) == false) {
		return (FAIL);
	}
	if (ft_is_same_length_of_lines(map, info) == false) {
		return (FAIL);
	}
	return (SUCCESS);
}
