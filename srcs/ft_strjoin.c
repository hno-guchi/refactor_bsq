/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:41:41 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/22 10:40:22 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static size_t	join_size(char const *s1, char const *s2)
{
	size_t	dstsize = 0;
	size_t	s2_siz = 0;

	if (s1 != NULL) {
		dstsize = ft_strlen(s1);
	}
	if (s2 != NULL) {
		s2_siz = ft_strlen(s2);
	}
	if (s2_siz < (SIZE_MAX - dstsize)) {
		dstsize += s2_siz + 1;
	}
	else {
		dstsize = SIZE_MAX;
	}
	return (dstsize);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dstsize = 0;
	char	*dst = NULL;

	if (s1 == NULL && s2 == NULL) {
		return (ft_strdup(""));
	}
	dstsize = join_size(s1, s2);
	dst = (char *)ft_calloc(dstsize, sizeof(char));
	if (dst == NULL) {
		return (NULL);
	}
	if (s1 == NULL && s2 != NULL) {
		(void)ft_strlcpy(dst, s2, dstsize);
	}
	else if (s1 != NULL && s2 == NULL) {
		(void)ft_strlcpy(dst, s1, dstsize);
	}
	else {
		(void)ft_strlcpy(dst, s1, dstsize);
		(void)ft_strlcat(dst, s2, dstsize);
	}
	return (dst);
}
