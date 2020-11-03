/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlacheny <mlacheny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:22:04 by mlacheny          #+#    #+#             */
/*   Updated: 2020/11/03 15:33:18 by mlacheny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	new_plane(t_scene *scene, char *str)
{
	t_obj	*obj;
	t_plane	*pl;

	if (!(obj = malloc(sizeof(*obj))))
		return (-1);
	if (!(pl = malloc(sizeof(*pl))))
		return (-1);
	obj->id = 2;
	valid_spacing(&str);
	valid_coord(&str, &pl->coord);
	valid_spacing(&str);
	valid_orient(&str, &pl->orien);
	valid_spacing(&str);
	valid_color(&str, &pl->color);
	obj->type = pl;
	ft_lstadd_back(&scene->objs, ft_lstnew(obj));
	return (1);
}

int new_carre(t_scene *scene, char *str)
{
	t_obj	*obj;
	t_carre	*sq;

	if (!(obj = malloc(sizeof(*obj))))
		return (-1);
	if (!(sq = malloc(sizeof(*sq))))
		return (-1);
	valid_spacing(&str);
	valid_coord(&str, &sq->coord);
	valid_spacing(&str);
	valid_orient(&str, &sq->orien);
	valid_spacing(&str);
	ft_atof(&str, &sq->size);
	valid_spacing(&str);
	valid_color(&str, &sq->color);
	obj->id = 3;
	obj->type = sq;
	ft_lstadd_back(&scene->objs, ft_lstnew(obj));
	return (1);
}

int	new_cy(t_scene *scene, char *str)
{
	t_cy	*cy;
	t_obj	*obj;

	if (!(cy = malloc(sizeof(*cy))))
		return (-1);
	if (!(obj = malloc(sizeof(*obj))))
		return (-1);
	valid_spacing(&str);
	valid_coord(&str, &cy->coord);
	valid_spacing(&str);
	valid_orient(&str, &cy->orien);
	valid_spacing(&str);
	ft_atof(&str, &cy->d);
	valid_spacing(&str);
	ft_atof(&str, &cy->h);
	valid_spacing(&str);
	valid_color(&str, &cy->color);
	obj->id = 4;
	obj->type = cy;
	ft_lstadd_back(&scene->objs, ft_lstnew(obj));
	return (1);
}

int	new_tr(t_scene *scene, char *str)
{
	t_tr	*tr;
	t_obj	*obj;
	int		i;

	i = -1;
	if (!(tr = malloc(sizeof(*tr))))
		return (-1);
	if (!(obj = malloc(sizeof(*obj))))
		return (-1);
	while (++i < 3)
	{
		valid_spacing(&str);
		valid_coord(&str, &tr->coord[i]);
	}
	valid_spacing(&str);
	valid_color(&str, &tr->color);
	obj->id = 5;
	obj->type = tr;
	ft_lstadd_back(&scene->objs, ft_lstnew(obj));
	return (1);
}
