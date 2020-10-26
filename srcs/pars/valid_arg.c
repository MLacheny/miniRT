/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:53:22 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/26 17:00:25 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_sp(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int valid_int(char **str)
{
	int i;

	i = 0;
	if (!is_sp(**str))
		return (0);
	while (is_sp(*(++(*str))));
	if (!ft_isdigit(**str))
		return (0);
	i = i * 10 + **str - '0';
	while (ft_isdigit(*(++(*str))))
		i = i * 10 + **str - '0';
	return (i);
}

int	valid_res(char *str, int *is_R)
{
	if (*is_R)
		return (-1);
	*is_R = 1;
	if (!valid_int(&str))
		return (-1);
	if (!valid_int(&str))
		return (-1);
	if (*str == 0)
		return (1);
	return (-1);
}

int	valid_color(char **str, t_color *color)
{
	if (atocolor(str, &(color->R)) == -1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (atocolor(str, &(color->G)) == -1)
		return (-1);
	if (*((*str)++) != ',')
		return (-1);
	if (atocolor(str, &(color->B)) == -1)
		return (-1);
	return (0);
}

int	valid_amb(char *str, int *is_A)
{
	int i;
	t_color color;

	i = 0;
	if (*is_A)
		return (-1);
	*is_A = 1;
	if (valid_stre(&str) == -1)
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
