/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 11:20:59 by mlacheny          #+#    #+#             */
/*   Updated: 2021/01/05 15:26:26 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	halfpi_x(t_cam *cam)
{
	cam->tra[0][0] = 1;
	cam->tra[0][1] = 0;
	cam->tra[0][2] = 0;
	cam->tra[0][3] = -cam->coord.x;
	cam->tra[1][0] = 0;
	cam->tra[1][1] = 0;
	cam->tra[1][2] = cam->orien.ry;
	cam->tra[1][3] = -cam->coord.z * cam->orien.ry;
	cam->tra[2][0] = 0;
	cam->tra[2][1] = -cam->orien.ry;
	cam->tra[2][2] = 0;
	cam->tra[2][3] = cam->coord.y * cam->orien.ry;
	cam->tra[3][0] = 0;
	cam->tra[3][1] = 0;
	cam->tra[3][2] = 0;
	cam->tra[3][3] = 1;
}

void	tetx_alphy(t_cam *cam, double t, double a)
{
	double alpha[2];
	double teta[2];

	printf("\nTeta : %f\nAlpha : %f", t, a);
	alpha[0] = cos(a);
	alpha[1] = sin(a);
	teta[0] = cos(t);
	teta[1] = sin(t);
	cam->tra[0][0] = alpha[0];
	cam->tra[0][1] = 0;
	cam->tra[0][2] = -alpha[1];
	cam->tra[0][3] = -cam->tra[0][0] * cam->coord.x - cam->tra[0][1] * cam->coord.y - cam->tra[0][2] * cam->coord.z;
	cam->tra[1][0] = teta[1] * alpha[1];
	cam->tra[1][1] = teta[0];
	cam->tra[1][2] = teta[1] * alpha[0];
	cam->tra[1][3] = -cam->tra[1][0] * cam->coord.x - cam->tra[1][1] * cam->coord.y - cam->tra[1][2] * cam->coord.z;
	cam->tra[2][0] = teta[0] * alpha[1];
	cam->tra[2][1] = -teta[1];
	cam->tra[2][2] = alpha[0] * teta[0];
	cam->tra[2][3] = -cam->tra[2][0] * cam->coord.x - cam->tra[2][1] * cam->coord.y - cam->tra[2][2] * cam->coord.z;
	cam->tra[3][0] = 0;
	cam->tra[3][1] = 0;
	cam->tra[3][2] = 0;
	cam->tra[3][3] = 1;
}

void	fill_mat_cam(t_cam *cam)
{
	double	teta;

	if (!cam->orien.rx && !cam->orien.rz)
	{
		halfpi_x(cam);
		return ;
	}
	teta = asin(cam->orien.ry);
	if (cam->orien.rz / cos(teta) < 0)
		tetx_alphy(cam, teta, asin(-cam->orien.rx / cos(teta)));
	else
		tetx_alphy(cam, teta, M_PI - asin(-cam->orien.rx / cos(teta)));
}

t_coord	coord_transfo(t_coord v1, double m21[4][4])
{
	t_coord	v2;

	v2.x = m21[0][0] * v1.x + m21[0][1] * v1.y + m21[0][2] * v1.z + m21[0][3];
	v2.y = m21[1][0] * v1.x + m21[1][1] * v1.y + m21[1][2] * v1.z + m21[1][3];
	v2.z = m21[2][0] * v1.x + m21[2][1] * v1.y + m21[2][2] * v1.z + m21[2][3];
	return (v2);
}

t_orien	orien_transfo(t_orien v1, double m21[4][4])
{
	t_orien v2;

	v2.rx = m21[0][0] * v1.rx + m21[0][1] * v1.ry + m21[0][2] * v1.rz + m21[0][3];
	v2.ry = m21[1][0] * v1.rx + m21[1][1] * v1.ry + m21[1][2] * v1.rz + m21[1][3];
	v2.rz = m21[2][0] * v1.rx + m21[2][1] * v1.ry + m21[2][2] * v1.rz + m21[2][3];
	return (v2);
}
