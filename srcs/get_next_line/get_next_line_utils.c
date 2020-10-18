/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:34:36 by mlacheny          #+#    #+#             */
/*   Updated: 2020/07/04 17:37:13 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_clear_line(int is_eof, char **line)
{
	line[0][0] = 0;
	return (is_eof);
}

int	ft_check_inputs(int fd, char **line)
{
	if (!line)
		return (0);
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 100000000)
	{
		*line = 0;
		return (0);
	}
	return (1);
}

int	ft_read(int fd, char *buff, char **line)
{
	int b_read;
	int i;

	if (!ft_update_line(line, buff, BUFFER_SIZE))
		return (-1);
	b_read = read(fd, buff, BUFFER_SIZE);
	if (b_read < 1)
		return (b_read);
	else if (b_read != BUFFER_SIZE)
	{
		i = b_read - 1;
		while (++i < BUFFER_SIZE)
			buff[i] = 0;
	}
	return (b_read);
}
