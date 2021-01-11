/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:15:34 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/06 14:56:34 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_orien	gen_ray(t_res res, t_cam cam, int index)
{
	int		i;
	int 	j;
	t_orien	ray;
	double	a;

	i = index % res.x;
	j = index / res.x;
	a = tan(cam.fov / 2);
	ray.x = -a + a * (2 * i + 1) / res.x;
	ray.y = -a * res.y / res.x + a * (2 * j + 1) / res.x;
	ray.z = -1;
	ray = to_norm(ray);
	return (ray);
}
