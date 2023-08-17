/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:38:49 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/17 10:52:27 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	**ft_frees(char **sp, size_t i)
{
	while (0 < i)
	{
		i -= 1;
		free(sp[i]);
	}
	free(sp);
	return (NULL);
}

static char	**make_split(char const *s, int c, char **sp, size_t cnt)
{
	size_t	sp_i;
	size_t	head_i;
	size_t	tail_i;

	sp_i = 0;
	head_i = 0;
	tail_i = 0;
	while (sp_i < (cnt - 1))
	{
		while (s[head_i] == c && s[head_i] != '\0')
			head_i += 1;
		tail_i = head_i;
		while (s[tail_i] != c && s[tail_i] != '\0')
			tail_i += 1;
		if (0 < (tail_i - head_i))
		{
			sp[sp_i] = ft_substr(&s[head_i], 0, tail_i - head_i);
			if (sp[sp_i] == NULL)
				return (ft_frees(sp, sp_i));
			sp_i += 1;
		}
		head_i = tail_i;
	}
	return (sp);
}

static size_t	count_split(char const *s, char c)
{
	size_t		s_len;
	size_t		head_i;
	size_t		tail_i;
	size_t		cnt;

	s_len = ft_strlen(s);
	head_i = 0;
	tail_i = 0;
	cnt = 1;
	while (head_i < s_len)
	{
		while (s[head_i] == c && head_i < s_len)
			head_i += 1;
		tail_i = head_i;
		while (s[tail_i] != c && tail_i < s_len)
			tail_i += 1;
		if (0 < (tail_i - head_i))
			cnt += 1;
		head_i = tail_i;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**split;

	if (s == NULL)
		return (NULL);
	cnt = count_split(s, c);
	split = (char **)ft_calloc(cnt, sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = make_split(s, c, split, cnt);
	return (split);
}


