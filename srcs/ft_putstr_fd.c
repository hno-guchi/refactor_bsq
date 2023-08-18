/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:41:22 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/08/18 17:41:48 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr_fd(int fd, const char *str)
{
	if (str == NULL) {
		return ;
	}
	size_t	str_size = ft_strlen(str);
	write(fd, str, str_size);
}
