/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:34:07 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/01 12:46:48 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		get_info(t_scene *scene, char *line)
{
	(void)scene;
	ft_putstr_fd(line, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}

int		check_line(char *line, int *is_AR)
{
	if (!line[0])
		return (1);
	if (ft_strlen(line) < 3)
		return (-1);
	if (line[0] == 'R' && is_sp(line[1]))
		return (valid_res(line + 1, is_AR + 1));
	else if (line[0] == 'A' && is_sp(line[1]))
		return (valid_amb(line + 1, is_AR));
	else if (line[0] == 'c' && is_sp(line[1]))
		return (valid_cam(line + 1));
	return (1);
}

int		check_lines_errors(int fd, int *is_AR)
{
	char	*line;
	int		error;

	while ((error = get_next_line(fd, &line)))
    {
        if (error == -1)
            return (-1);
        while (!line[0] && error)
        {
            free(line);
            error = get_next_line(fd, &line);
            if (error == -1)
                return (-1);
        }
		error = check_line(line, is_AR);
        free(line);
        if (error == -1)
            return (0);
    }
	return (1);
} 

int		check_config_file(int *fd, int argc, char **argv)
{
	int		error;
	int 	is_AR[2];

	is_AR[0] = 0;
	is_AR[1] = 0;
	if ((error = check_lines_errors(*fd, is_AR)) != 1)
	{
		close(*fd);
		return (error);
	}
	if (!is_AR[0] || !is_AR[1])
	{
		close(*fd);
		return (0);
	}
	close(*fd);
	if ((*fd = handle_err(argc, argv)) == -1)
		return (2);
	return (1);
}

int		fill_scene(t_scene *scene, int *fd, int argc, char **argv)
{
	char	*line;
	int		error;

	if ((error = check_config_file(fd, argc, argv)) != 1)
		return (error);
	while ((error = get_next_line(*fd, &line)))
	{
		if (error == -1)
			return (-1);
		while (!line[0] && error)
		{
			free(line);
			error = get_next_line(*fd, &line);
			if (error == -1)
				return (-1);
		}
		if (line[0])
			get_info(scene, line);
		free(line);
	}
	return (1);
}
