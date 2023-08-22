/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:34:30 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/22 10:46:29 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len = 0;

	while (len < n) {
		if (s[len] == '\0') {
			break ;
		}
		len += 1;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i = 0;
	size_t	d_len = ft_strnlen(dst, dstsize);
	size_t	s_len = ft_strlen(src);
	size_t	lcat_siz;

	if (dstsize <= d_len) {
		return (dstsize + s_len);
	}
	if (s_len < (dstsize - d_len - 1)) {
		lcat_siz = s_len + 1;
	}
	else {
		lcat_siz = dstsize - d_len - 1;
	}
	while (i < lcat_siz) {
		dst[d_len + i] = src[i];
		i += 1;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
