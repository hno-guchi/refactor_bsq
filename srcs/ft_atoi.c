/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:51:43 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/18 17:09:58 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int res;
	int sign;
	int i;

	res = 0;
	sign = 0;
	i = 0;
	while (ft_isspace(str[i])) {
		i++;
	}
	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-') {
			sign++;
		}
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i])) {
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (sign % 2 == 1) {
		return (res * -1);
	}
	return (res);
}
