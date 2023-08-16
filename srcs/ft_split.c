/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:59:31 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/16 10:47:24 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		g_word_index = 0;
int		g_start = 0;
int		g_end = 0;
int		g_state = 0;

static bool	is_in_charset(char c, char *charset)
{
	size_t	i = 0;

	while (charset[i]) {
		if (charset[i] == c) {
			return (true);
		}
		i += 1;
	}
	return (false);
}

static int	get_word_count(char *str, char *charset)
{
	size_t	i = 0;
	int		wc = 0;
	int		state = OUT;

	while (str[i] != '\0')
	{
		if (is_in_charset(str[i], charset)) {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			wc += 1;
		}
		i += 1;
	}
	return (wc);
}

void	ft_update_in_word(int i)
{
	if (g_state == OUT)
	{
		g_state = IN;
		g_start = i;
		g_end = i;
	}
	else
		g_end = i;
}

void	ft_add_last_word(char **res, char *str, int i)
{
	int j;

	if (g_state == IN)
	{
		res[g_word_index] = malloc(sizeof(char) * ((i - g_start) + 1));
		j = -1;
		while (g_start <= i)
			res[g_word_index][++j] = str[g_start++];
		res[g_word_index][++j] = '\0';
		g_word_index++;
	}
	res[g_word_index] = 0;
	g_word_index = 0;
	g_start = 0;
	g_end = 0;
	g_state = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**res = NULL;
	int		i = 0;
	int		j = 0;

	res = malloc(sizeof(char *) * (get_word_count(str, charset) + 1));
	while (str[i] != '\0')
	{
		if (is_in_charset(str[i], charset) && g_state == IN) {
			g_state = OUT;
			res[g_word_index] = malloc(sizeof(char) * ((g_end - g_start) + 1));
			j = 0;
			while (g_start <= g_end) {
				res[g_word_index][j] = str[g_start];
				j += 1;
				g_start += 1;
			}
			res[g_word_index][j] = '\0';
			g_word_index += 1;
		}
		else {
			ft_update_in_word(i);
		}
		i += 1;
	}
	ft_add_last_word(res, str, i);
	return (res);
}
