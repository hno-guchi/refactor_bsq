/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:44:48 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/15 23:02:31 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return (i);
}
