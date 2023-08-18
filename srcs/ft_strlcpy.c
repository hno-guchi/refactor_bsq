/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:15:21 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/17 10:46:23 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_size;

	i = 0;
	s_size = ft_strlen(src);
	if (src != NULL && 0 < dstsize)
	{
		while (i < s_size && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i += 1;
		}
		dst[i] = '\0';
	}
	return (s_size);
}
