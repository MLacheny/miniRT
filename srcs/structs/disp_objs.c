/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:02:52 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/03 15:43:30 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void display_objs(t_list *obj)
{
	ft_putstr_fd("\nOBJECTS :\n\n", 1);
	while(obj)
	{
		if (((t_obj *)obj->content)->id == 1)
			display_sphere(*((t_sp *)((t_obj *)obj->content)->type));
		if (((t_obj *)obj->content)->id == 2)
			display_plane(*((t_plane *)((t_obj *)obj->content)->type));
		if (((t_obj *)obj->content)->id == 3)
			display_carre(*((t_carre *)((t_obj *)obj->content)->type));
		if (((t_obj *)obj->content)->id == 4)
			display_cy(*((t_cy *)((t_obj *)obj->content)->type));
		if (((t_obj *)obj->content)->id == 5)
			display_tr(*((t_tr *)((t_obj *)obj->content)->type));
		obj = obj->next;
	}
}

void display_sphere(t_sp sp)
{
	ft_putstr_fd("\nSPHERE :\n\n", 1);
	printf("POS X : %f\n", sp.coord.x);
	printf("POS Y : %f\n", sp.coord.y);
	printf("POS Z : %f\n", sp.coord.z);
	printf("DIAMETRE : %f\n", sp.diam);
	printf("R : %d\n", sp.color.R);
	printf("G : %d\n", sp.color.G);
	printf("B : %d\n", sp.color.B);
}

void display_plane(t_plane pl)
{
	ft_putstr_fd("\nPLANE :\n\n", 1);
	printf("POS X : %f\n", pl.coord.x);
	printf("POS Y : %f\n", pl.coord.y);
	printf("POS Z : %f\n", pl.coord.z);
	printf("ORIENTATION SUR X : %f\n", pl.orien.rx);
	printf("ORIENTATION SUR Y : %f\n", pl.orien.ry);
	printf("ORIENTATION SUR Z : %f\n", pl.orien.rz);
	printf("R : %d\n", pl.color.R);
	printf("G : %d\n", pl.color.G);
	printf("B : %d\n", pl.color.B);
}

void display_carre(t_carre sq)
{
	ft_putstr_fd("\nSQUARE :\n\n", 1);
	printf("POS X : %f\n", sq.coord.x);	
	printf("POS Y : %f\n", sq.coord.y);	
	printf("POS Z : %f\n", sq.coord.z);	
	printf("ORIENTATION SUR X : %f\n", sq.orien.rx);
	printf("ORIENTATION SUR Y : %f\n", sq.orien.ry);
	printf("ORIENTATION SUR Z : %f\n", sq.orien.rz);
	printf("SIZE : %f\n", sq.size);	
	printf("R : %d\n", sq.color.R);	
	printf("G : %d\n", sq.color.G);	
	printf("B : %d\n", sq.color.B);	
}

void display_cy(t_cy cy)
{	
	ft_putstr_fd("\nCYLINDRE :\n\n", 1);
	printf("POS X : %f\n", cy.coord.x);	
	printf("POS Y : %f\n", cy.coord.y);	
	printf("POS Z : %f\n", cy.coord.z);	
	printf("ORIENTATION SUR X : %f\n", cy.orien.rx);
	printf("ORIENTATION SUR Y : %f\n", cy.orien.ry);
	printf("ORIENTATION SUR Z : %f\n", cy.orien.rz);
	printf("DIAMETRE : %f\n", cy.d);
	printf("HEIGHT : %f\n", cy.h);
	printf("R : %d\n", cy.color.B);	
	printf("G : %d\n", cy.color.B);	
	printf("B : %d\n", cy.color.B);		
}

void display_tr(t_tr tr)
{
	int i;

	i = -1;
	ft_putstr_fd("\nTRIANGLE :\n\n", 1);
	while (++i < 3)
	{
		printf("POS X%d : %f\n", i, tr.coord[i].x);	
		printf("POS Y%d : %f\n", i, tr.coord[i].y);	
		printf("POS Z%d : %f\n", i, tr.coord[i].z);	
	}
}
