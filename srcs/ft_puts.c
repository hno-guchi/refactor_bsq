/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisnop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:46:13 by louisnop          #+#    #+#             */
/*   Updated: 2023/08/16 10:00:47 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(int fd, const char *str)
{
	if (str == NULL) {
		return ;
	}
	size_t	str_size = ft_strlen(str);
	write(fd, str, str_size);
}

void	error_message(const char *message)
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
