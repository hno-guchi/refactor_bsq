/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:16:39 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/18 17:53:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	cal_siz;

	temp = NULL;
	cal_siz = 0;
	if (count == 0 || size == 0) {
		cal_siz = 1;
	}
	else if ((SIZE_MAX / size) < count) {
		cal_siz = SIZE_MAX;
	}
	else {
		cal_siz = count * size;
	}
	temp = malloc(cal_siz);
	if (temp == NULL) {
		return (NULL);
	}
	ft_bzero(temp, cal_siz);
	return (temp);
}
