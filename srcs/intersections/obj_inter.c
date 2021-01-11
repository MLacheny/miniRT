/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:42:03 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/11 10:35:34 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

double	sp_inter(t_orien ray, t_sp sp)
{
	double tca;
	double thc;
	double d;

	tca = dot_product(ortocoord(ray), sp.coord);
	if (tca < 0)
		return (-1);
	d = sqrt(dot_product(sp.coord, sp.coord) - pow(tca, 2));
	if (d > sp.diam)
		return (-1);
	thc = 
}

double	compute_inter(t_orien ray, t_cam cam)
{
	double d_min;
	double d;

	d_min = -1;
	while (cam.obj)
	{
		if (((t_obj *)cam.obj->content)->id == 1)
			d = sp_inter(ray, *(t_sp *)((t_obj *)cam.obj->content)->type);
		if (((t_obj *)cam.obj->content)->id == 2)
			d = pl_inter(ray, *(t_plane *)((t_obj *)cam.obj->content)->type);
		if (((t_obj *)cam.obj->content)->id == 3)
			d = sq_inter(ray, *(t_carre *)((t_obj *)cam.obj->content)->type);
		if (((t_obj *)cam.obj->content)->id == 4)
			d = cy_inter(ray, *(t_cy *)((t_obj *)cam.obj->content)->type);
		if (((t_obj *)cam.obj->content)->id == 5)
			d = tr_inter(ray, *(t_tr *)((t_obj *)cam.obj->content)->type);
		if (d_min == -1 || d_min > d)
			d_min = d;
		cam.obj = cam.obj->next;
	}
}
