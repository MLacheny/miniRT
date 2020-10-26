/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:49:15 by mlacheny          #+#    #+#             */
/*   Updated: 2020/10/20 17:01:00 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	set_color(unsigned char R, unsigned char G, unsigned char B)
{
	t_color color;

	color.R = R;
	color.G = G;
	color.B = B;
	return (color);
}

t_orien	set_orien(float rx, float ry, float rz)
{
	t_orien orien;

	orien.rx = rx;
	orien.ry = ry;
	orien.rz = rz;
	return (orien);
}

t_coord	set_coord(int x, int y, int z)
{
	t_coord coord;

	coord.x = x;
	coord.y = y;
	coord.z = z;
	return (coord);
}
