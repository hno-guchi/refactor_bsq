/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:46:10 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/18 17:58:28 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	while (src[i] != '\0') {
		i++;
	}
	if (!(res = (char *)malloc(i + 1))) {
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0') {
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
