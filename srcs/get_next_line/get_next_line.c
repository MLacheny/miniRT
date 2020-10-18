/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:51:35 by mlacheny          #+#    #+#             */
/*   Updated: 2020/07/04 17:35:44 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_end(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_update_line(char **line, char *buff, int b_size)
{
	int		i;
	int		size;
	char	*backup;

	if (b_size == -1)
		return (1);
	size = ft_strlen(line[0]);
	if (!(backup = malloc(sizeof(**line) * (size + 1))))
		return (0);
	i = -1;
	while (line[0][++i])
		backup[i] = line[0][i];
	free(line[0]);
	if (!(line[0] = malloc(sizeof(**line) * (size + b_size + 1))))
		return (0);
	i = -1;
	while (++i < size)
		line[0][i] = backup[i];
	i = -1;
	free(backup);
	while (++i < b_size)
		line[0][size + i] = buff[i];
	line[0][size + i] = 0;
	return (1);
}

void	ft_update_buff(char *buff, int i_nl)
{
	int		i;

	if (i_nl == -1)
		return ;
	i = -1;
	while (++i < BUFFER_SIZE - i_nl - 1)
		buff[i] = buff[i + i_nl + 1];
	buff[BUFFER_SIZE - i_nl - 1] = 0;
	while (++i < BUFFER_SIZE)
		buff[i] = 0;
	return ;
}

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			i_nl;
	int			is_eof;

	if (!ft_check_inputs(fd, line))
		return (-1);
	if (!(*line = malloc(sizeof(**line))))
		return (-1);
	**line = 0;
	if (!buff[0])
	{
		if ((is_eof = read(fd, &buff, BUFFER_SIZE)) < 1)
			return (ft_clear_line(is_eof, line));
	}
	while ((i_nl = ft_strchr_end(buff) == -1))
	{
		if ((is_eof = ft_read(fd, buff, line)) < 1)
			return (is_eof);
	}
	i_nl = ft_strchr_end(buff);
	if (!ft_update_line(line, buff, i_nl))
		return (-1);
	ft_update_buff(buff, i_nl);
	return (1);
}
