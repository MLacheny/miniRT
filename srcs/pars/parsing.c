/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:34:18 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/05 16:39:04 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_dot(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			return (i + 1);
	}
	return (-1);
}

int valid_ext(char *str)
{
	int i;
	int is_ext;

	if (!str[0])
		return (1);
	i = 0;
	while ((is_ext = is_dot(str + i)) != -1)
		i += is_ext;
	if (!ft_strncmp("rt", str + i, 3))
		return (1);
	return (0);
}

int	handle_err(int argc, char **argv)
{
	int fd;

	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" : wrong number of arguments\n", 2);
		return (-1);
	}
	if (!valid_ext(argv[1]))
	{
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" : invalid scene description file\n", 2);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr_fd(argv[0], 2);
		perror(" : ");
		return (-1);
	}
	return (fd);
}

int	handle_gnl_err(char *pname, int error_type, int fd)
{
	if (error_type == -1)
	{
		ft_putstr_fd(pname, 2);
		ft_putstr_fd(" : error while reading in file\n", 2);
	}
	else if (error_type == 0)
	{
		ft_putstr_fd(pname, 2);
		ft_putstr_fd(" : inccorect parameters in configuration file\n", 2);
	}
	else if (error_type == -2)
	{
		ft_putstr_fd(pname, 2);
		ft_putstr_fd(" : error while allocating memory\n", 2);	
	}
	else
		return (1);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	int 	fd;
	int 	err_type;
	t_scene	scene;

	scene = def_scene();
	if ((fd = handle_err(argc, argv)) == -1)
		return (1);
	if ((err_type = fill_scene(&scene, &fd, argc, argv)) != 1)
		return (handle_gnl_err(argv[0], err_type, fd));
	//create_views(scene);
	objtocam(&scene);
	display_scene(scene);
	return (0);
}
