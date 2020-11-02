/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:53:22 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/02 11:10:26 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_res(char *str, int *is_R)
{
	if (*is_R)
		return (-1);
	*is_R = 1;
	if (ft_atoint(&str) <= 0)
		return (-1);
	if (ft_atoint(&str) <= 0)
		return (-1);
	if (*str == 0)
		return (1);
	return (-1);
}

int	valid_amb(char *str, int *is_A)
{
	t_color	color;
	float	f;

	if (*is_A)
		return (-1);
	*is_A = 1;
	if (valid_spacing(&str) == -1)
		return (-1);
	if (ft_atof(&str, &f) == -1)
		return (-1);
	if (f < 0 || f > 1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &color) == -1)
		return (-1);
	(void)color;
	if (*str == 0)
		return (1);
	return (-1);
}

int	valid_cam(char *str)
{
	t_cam cam;

	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_coord(&str, &cam.coord) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_orient(&str, &cam.orien) == -1)
		return (-1);
	if ((cam.fov = ft_atoint(&str)) < 0 || cam.fov > 180)
		return (-1);
	(void)cam;
	if (!*str)
		return (0);
	return (-1);
}

int	valid_light(char *str)
{
	t_light	l;

	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_coord(&str, &l.coord) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (ft_atof(&str, &l.stren) == -1 || l.stren < 0 || l.stren > 1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &l.color) == -1)
		return (-1);
	(void)l;
	if (!*str)
		return (0);
	return (-1);
}

int	valid_sphere(char *str)
{
	t_sp sp;

	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_coord(&str, &sp.coord) == -1)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (ft_atof(&str, &sp.diam) == -1 || sp.diam <= 0)
		return (-1);
	if (valid_spacing(&str) == -1)
		return (-1);
	if (valid_color(&str, &sp.color) == -1)
		return (-1);
	if (!*str)
		return (0);
	return (-1);
}
