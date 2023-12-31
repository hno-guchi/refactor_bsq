/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:47:47 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/18 17:34:02 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// bool	ft_isdigit(const char c) {
// 	return ('0' <= c && c <= '9');
// }

int		ft_validate_5(char **map)
{
	int		len;
	char	*line;
	int		i;

	if (!map[0])
		return (FAIL);
	line = map[0];
	len = ft_strlen(line);
	if (len < 4)
		return (FAIL);
	i = -1;
	while (++i < len - 3) {
		// if (!(line[i] >= '0' && line[i] <= '9')) {
		if (ft_isdigit(line[i]) == false) {
			return (FAIL);
		}
	}
	if (!(ft_isprint(line[len - 1]) && ft_isprint(line[len - 2]) && ft_isprint(line[len - 3]))) {
		return (FAIL);
	}
	if (line[len - 1] == line[len - 2] || line[len - 2] == line[len - 3] || line[len - 3] == line[len - 1]) {
		return (FAIL);
	}
	return (SUCCESS);
}

t_info	*ft_prse(char **map)
{
	t_info	*info;
	char	*line;
	int		len;
	int		i;
	char	*num;

	line = map[0];
	len = ft_strlen(line);
	info = malloc(sizeof(t_info *));
	num = malloc(sizeof(char) * (len - 3) + 1);
	i = -1;
	while (++i < len - 3) {
		num[i] = line[i];
	}
	num[i] = '\0';
	info->num_rows = ft_atoi(num);
	info->empty = line[len - 3];
	info->obstacle = line[len - 2];
	info->full = line[len - 1];
	free(num);
	return (info);
}
