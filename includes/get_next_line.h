/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:52:38 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/18 16:26:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H
#	define BUFFER_SIZE 255

#include <stdlib.h>
#include <unistd.h>

int	get_next_line(int fd, char **line);
int	ft_clear_line(int is_eof, char **line);
int	ft_check_inputs(int fd, char **line);
int	ft_update_line(char **line, char *buff, int b_size);
int	ft_read(int fd, char *buff, char **line);

#	endif
