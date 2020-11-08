/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:14:26 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/08 18:12:37 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int is_sp(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	valid_spacing(char **str)
{
	if (!is_sp(**str))
		return (-1);
	while (is_sp(*(++(*str))));
	return (0);
}

int valid_color(char **str, t_color *color)
{
	if (ft_atocolor(str, &(color->R)) == -1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (ft_atocolor(str, &(color->G)) == -1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (ft_atocolor(str, &(color->B)) == -1)
		return (-1);
	return (0);
}

int	valid_coord(char **str, t_coord *coord)
{
	if (ft_atof(str, &coord->x) == -1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (ft_atof(str, &coord->y) == -1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (ft_atof(str, &coord->z) == -1)
		return (-1);
	return (0);
}

int	valid_orient(char **str, t_orien *orien)
{
	if (ft_atof(str, &orien->rx) == -1 || orien->rx < -1 || orien->rx > 1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (ft_atof(str, &orien->ry) == -1 || orien->ry < -1 || orien->ry > 1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (ft_atof(str, &orien->rz) == -1 || orien->rz < -1 || orien->rz > 1)
		return (-1);
	if (!orien->rx && !orien->ry && !orien->rz)
		return (-1);
	*orien = to_norm(*orien);
	return (0);
}
