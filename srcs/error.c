/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:46:13 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/18 17:50:40 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	error_message(const char *message)
{
	ft_putstr_fd(STDERR_FILENO, ERROR_PREFIX);
	ft_putstr_fd(STDERR_FILENO, message);
	ft_putchar_fd(STDERR_FILENO, '\n');
}

void	map_error_exit(t_error_kind type)
{
	switch(type) {
		case NOT_EXIST_LAST_NEWLINE:
			error_message(ERROR_NOT_EXIST_NEWLINE);
			break;
		default:
			break;
	};
	exit(EXIT_FAILURE);
}

void	fatal_error(const char *location)
{
	ft_putstr_fd(STDERR_FILENO, FATAL_ERROR_PREFIX);
	ft_putstr_fd(STDERR_FILENO, location);
	ft_putchar_fd(STDERR_FILENO, '\n');
	exit(EXIT_FAILURE);
}
