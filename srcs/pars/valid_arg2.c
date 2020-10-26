/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:20:17 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/26 17:01:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		atocolor(char **str, unsigned char *p)
{
	int	i;

	i = 0;
	if (!ft_isdigit(**str))
		return (-1);
	i = i * 10 + **str - '0';
	while (ft_isdigit(*(++(*str))))
		i = i * 10 + **str - '0';
	if (0 > i || i > 255)
		return (-1);
	*p = (unsigned char)i;
	return (0);
}

float	valid_stre(char **str)
{
	float e;
	float d;

	e = 0;
	d = 0;
	if (!is_sp(**str))
		return (-1);
	while (is_sp(*(++(*str))))
	if (!ft_isdigit(**str))
		return (-1);
	e = e * 10 + **str - '0';
	while (ft_isdigit(*(++(*str))))
		e = e * 10 + **str - '0';
	if (**str != '.')
		return (-1);
	if (!ft_isdigit(*(++(*str))))
		return (-1);
	d = (d + **str - '0') / 10;
	while (ft_isdigit(*(++(*str))))
		d = (d + **str - '0') / 10;
	if (e + d > 1 || e + d < 0)
		return (-1);
	return (e + d);
}

int		valid_spacing(char **str)
{
	if (!is_sp(**str))
		return (-1);
	while (is_sp(*(++(*str))));
	return (0);
}

/*int		valid_cam(char *str)
{
	
}*/
