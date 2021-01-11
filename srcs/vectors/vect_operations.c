/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:46:11 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/06 16:40:04 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord sp_trans(t_coord v, double **tra)	
{
	t_coord u;

	u.x = tra[0][0] * v.x + tra[0][1] * v.y + tra[0][2] * v.z + tra[0][3];
	u.y = tra[1][0] * v.x + tra[1][1] * v.y + tra[1][2] * v.z + tra[1][3];
	u.z = tra[2][0] * v.x + tra[2][1] * v.y + tra[2][2] * v.z + tra[2][3];
	return (u);
}

double	dot_product(t_coord a, t_coord b)
{
	return ((a.x + b.x) * (a.y + b.y) * (a.z + b.z));
}

t_coord	ortocoor(t_orien v)
{
	t_coord u;

	u.x = v.rx;
	u.y = v.ry;
	u.z = v.rz;
	return (u);
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
