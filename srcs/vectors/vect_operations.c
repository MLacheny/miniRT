/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:46:11 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/08 18:14:04 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	dot_product(t_coord a, t_coord b)
{
	return ((a.x + b.x) * (a.y + b.y) * (a.z + b.z));
}

t_coord	vect_add(t_coord a, t_coord b, char op)
{
	t_coord res;

	if (op != '-')
	{
		res.x = a.x + b.x;
		res.y = a.y + b.y;
		res.z = a.z + b.z;
	}
	else
	{
		res.x = a.x - b.x;
		res.y = a.y - b.y;
		res.z = a.z - b.z;
	}
	return (res);
}

t_orien	to_norm(t_orien o)
{
	t_orien res;
	double	l;

	l = sqrt(pow(o.rx, 2) + pow(o.ry, 2) + pow(o.rz, 2));
	res.rx = o.rx / l;
	res.ry = o.ry / l;
	res.rz = o.rz / l;
	return (res);
}
