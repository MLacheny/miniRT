/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:27:36 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/11 14:50:14 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void display_scene(t_scene scene)
{
	display_res(scene.res);
	display_lumamb(scene.lum_amb);
	display_cams(scene.cam);
	display_lights(scene.light);
	display_objs(scene.objs);
}

void display_res(t_res res)
{
	ft_putstr_fd("\nRESOLUTION :\n\n", 1);
	printf("Sur x : %d\n", res.x);
	printf("Sur y : %d\n", res.y);
}

void display_lumamb(t_lum_amb lum_amb)
{
	ft_putstr_fd("\nLUMIERE AMBIANTE :\n\n", 1);
	printf("Ratio : %f\n", lum_amb.stren);
	printf("R : %d\n", lum_amb.color.R);
	printf("G : %d\n", lum_amb.color.G);
	printf("B : %d\n", lum_amb.color.B);
}

void display_cams(t_list *cam)
{
	ft_putstr_fd("\nCAMERAS :\n\n", 1);
	while (cam)
	{
		printf("POS X : %f\n", ((t_cam *)cam->content)->coord.x);
		printf("POS Y : %f\n", ((t_cam *)cam->content)->coord.y);
		printf("POS Z : %f\n", ((t_cam *)cam->content)->coord.z);
		printf("ORIENTATION SUR X : %f\n", ((t_cam *)cam->content)->orien.rx);
		printf("ORIENTATION SUR Y : %f\n", ((t_cam *)cam->content)->orien.ry);
		printf("ORIENTATION SUR Z : %f\n", ((t_cam *)cam->content)->orien.rz);
		printf("FOV : %d\n\n", ((t_cam *)cam->content)->fov);
		printf("Transfo matrice :\n\n");
		for (int i = 0; i < 4; i++)
		{
			printf("|   ");
			for (int j = 0; j < 4; j++)
			{
				printf("%f  ", ((t_cam *)cam->content)->tra[i][j]);
			}
			printf("    |\n\n");
		}
		cam = cam->next;
	}
}

void display_lights(t_list *light)
{	
	ft_putstr_fd("\nLIGHTS :\n\n", 1);
	while (light)
	{
		printf("POS X : %f\n", ((t_light *)light->content)->coord.x);
		printf("POS Y : %f\n", ((t_light *)light->content)->coord.y);
		printf("POS Z : %f\n", ((t_light *)light->content)->coord.z);
		printf("Ratio : %f\n", ((t_light *)light->content)->stren);
		printf("R : %d\n", ((t_light *)light->content)->color.R);
		printf("G : %d\n", ((t_light *)light->content)->color.G);
		printf("B : %d\n\n", ((t_light *)light->content)->color.B);
		light = light->next;
	}
}
