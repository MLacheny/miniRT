/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atonum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:13:13 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/02 14:43:45 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_atocolor(char **str, unsigned char *p)
{
	int i;

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

float	get_dec(char **str)
{
	float	d;
	int		i;

	d = 0;
	i = 0;
	while (ft_isdigit((*str)[++i]));
	while (--i >= 0)
		d = (d + (*str)[i] - '0') / 10;
	while (ft_isdigit(*(++(*str))));
	return (d);
}

int		ft_atof(char **str, float *f)
{
	float	e;
	float	d;
	int		sign;

	sign = 1;
	e = 0;
	d = 0;
	if (**str == '-' && *((*str)++))
		sign *= -1;
	if (!ft_isdigit(**str))
		return (-1);
	e = e * 10 + **str - '0';
	while (ft_isdigit(*(++(*str))))
		e = e * 10 + **str - '0';
	if (**str == '.')
	{
		if (!ft_isdigit(*(++(*str))))
			return (-1);
		d = get_dec(str);
	}
	*f = (e + d) * sign;
	return (0);
}

int 	ft_atoint(char **str)
{
	int i;

	i = 0;
	if (!is_sp(**str))
		return (-1);
	while (is_sp(*(++(*str))));
	if (!ft_isdigit(**str))
		return (-1);
	i = i * 10 + **str - '0';
	while (ft_isdigit(*(++(*str))))
		i = i * 10 + **str - '0';
	return (i);
}
